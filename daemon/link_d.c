#include "link_d.h"

/*
 * LINK_D
 *
 * Central link registry + resolver.
 *
 * Goals:
 *  - Topology is defined externally (e.g., JSON area files, world scripts)
 *  - Exactly one Link instance per unordered endpoint pair
 *  - Link definitions are immutable once registered
 *  - Never loads environments (no load_object / find_object required)
 *  - Rooms DISCOVER links by asking LINK_D for their incident links
 *
 * What this daemon supports:
 *  - Loading links from JSON files containing:
 *      {
 *        "area_prefix": "/chapter/prologue/area/demo/",
 *        "links": [
 *          {
 *            "link": { "cell": "east", "guardroom": "west" }
 *          }
 *        ]
 *      }
 *  - Relative endpoints resolved against area_prefix; absolute endpoints unchanged
 *  - Direction labels per endpoint (east/west/etc) stored as metadata in definition
 *  - Index by room for fast "what links touch this room?"
 *
 * Notes:
 *  - This daemon does NOT implement movement; it only provides link objects
 *    + enough metadata to power movement/exits UI elsewhere.
 *  - Gate logic is supported by named gate IDs (recommended), or gate objects.
 */

mapping _links;            /* pair_key -> Link object */
mapping _definitions;      /* pair_key -> definition mapping (immutable) */
mapping _links_by_room;    /* room_abs -> ({ pair_key, ... }) */
mapping _dir_claims;       /* room_abs -> ([ dir_label : pair_key ]) */

string pair_key(string a, string b);
int define_link(string env_a, string env_b, mapping definition);

/* ------------------------------------------------------------ */

void create() {
  string *link_files;
  int i;

  _links         = ([]);
  _definitions   = ([]);
  _links_by_room = ([]);
  _dir_claims    = ([]);
  link_files = ({
    "/chapter/prologue/area/dead/links.json",
    "/chapter/prologue/area/roadway/links.json",
    "/chapter/prologue/area/wilderness/wilderness_links.json",
    "/chapter/prologue/area/refuge/links.json",
    "/chapter/prologue/area/ruined/ruined_links.json",
    "/chapter/prologue/area/silent/links.json",
    "/chapter/prologue/area/sunken/links.json",
  });

  i = 0;

  while (i < sizeof(link_files)) {
    load_json(link_files[i]);

    i += 1;
  }
  load_wilderness_room_links();
}

/* ------------------------------------------------------------ */
/* Utilities
 * ------------------------------------------------------------ */

string _trim(string s) {
  if (!stringp(s)) return "";

  return trim(s);
}

string _definition_source(mapping definition) {
  string source;

  if (!mapp(definition))
    return "unknown";

  source = definition["source"];

  if (!stringp(source) || _trim(source) == "")
    return "unknown";

  return _trim(source);
}

string _format_definition_ref(string key, mapping definition) {
  string *eps;
  string a, b, source;

  eps = endpoints_from_key(key);

  if (sizeof(eps) != 2)
    return "unknown";

  a = eps[0];
  b = eps[1];
  source = _definition_source(definition);

  return a + " <-> " + b + " (defined in " + source + ")";
}

mixed parse_json(string raw) {
  object parser;

  if (!stringp(raw) || raw == "")
    return 0;

  parser = find_object("/std/json");

  if (!objectp(parser))
    parser = load_object("/std/json");

  if (!objectp(parser))
    return 0;

  return parser->json_decode(raw);
}

string read_json_file(string file) {
  string chunk, contents;
  string *chunks;
  int line, line_count;

  if (!stringp(file) || file == "")
    return 0;

  chunks = ({ });
  line = 1;
  line_count = 500;

  while (1) {
    chunk = read_file(file, line, line_count);

    if (!stringp(chunk))
      break;

    chunks += ({ chunk });
    line += line_count;
  }

  if (!sizeof(chunks))
    return 0;

  contents = implode(chunks, "");

  if (!stringp(contents) || contents == "")
    return 0;

  return contents;
}

int _is_wilderness_endpoint(string endpoint) {
  if (!stringp(endpoint) || endpoint == "")
    return 0;

  return (strsrch(endpoint, "/chapter/prologue/area/wilderness/wilderness_room#") == 0);
}

string _opposite_direction(string dir) {
  dir = _trim(dir);

  if (dir == "north") return "south";
  if (dir == "south") return "north";
  if (dir == "east") return "west";
  if (dir == "west") return "east";
  if (dir == "northeast") return "southwest";
  if (dir == "northwest") return "southeast";
  if (dir == "southeast") return "northwest";
  if (dir == "southwest") return "northeast";
  if (dir == "up") return "down";
  if (dir == "down") return "up";

  return "";
}

string _wilderness_endpoint_from_id(string room_id) {
  room_id = _trim(room_id);

  if (room_id == "")
    return "";

  return "/chapter/prologue/area/wilderness/wilderness_room#" + room_id;
}

void load_wilderness_room_links() {
  string *map_files;
  string raw, source_file, from_id, to_ref, from_ep, to_ep, pair;
  string from_dir, opposite_dir;
  mapping data, room_entry, exits, pair_defs, def, rooms_by_file, room_ids;
  mixed rooms;
  int i, j;

  map_files = ({
    "/chapter/prologue/area/wilderness/wilderness_nw.json",
    "/chapter/prologue/area/wilderness/wilderness_sw.json",
    "/chapter/prologue/area/wilderness/wilderness_ne.json",
    "/chapter/prologue/area/wilderness/wilderness_se.json"
  });
  pair_defs = ([ ]);
  rooms_by_file = ([ ]);
  room_ids = ([ ]);
  i = 0;

  /* Pass 1: parse files and collect all wilderness IDs. */
  while (i < sizeof(map_files)) {
    source_file = map_files[i];
    raw = read_json_file(source_file);

    if (!stringp(raw)) {
      write("LINK_D: Unable to read wilderness map file: " + source_file + "\n");
      i += 1;

      continue;
    }

    data = parse_json(raw);

    if (!mapp(data)) {
      write("LINK_D: Invalid wilderness JSON in: " + source_file + "\n");
      i += 1;

      continue;
    }

    rooms = data["rooms"];

    if (!pointerp(rooms)) {
      write("LINK_D: Wilderness JSON missing rooms array in: " + source_file + "\n");
      i += 1;

      continue;
    }
    rooms_by_file[source_file] = rooms;

    j = 0;

    while (j < sizeof(rooms)) {
      room_entry = rooms[j];

      if (mapp(room_entry)) {
        from_id = room_entry["id"];

        if (stringp(from_id) && _trim(from_id) != "")
          room_ids[_trim(from_id)] = 1;
      }

      j += 1;
    }

    i += 1;
  }

  /* Pass 2: build link definitions only for destinations that exist. */
  i = 0;

  while (i < sizeof(map_files)) {
    source_file = map_files[i];
    rooms = rooms_by_file[source_file];

    if (!pointerp(rooms)) {
      i += 1;

      continue;
    }

    j = 0;

    while (j < sizeof(rooms)) {
      room_entry = rooms[j];

      if (mapp(room_entry)) {
        from_id = room_entry["id"];
        exits = room_entry["exits"];

        if (stringp(from_id) && mapp(exits)) {
          from_id = _trim(from_id);
          from_ep = _wilderness_endpoint_from_id(from_id);

          foreach (mixed k, mixed v in exits) {
            if (!stringp(k) || !stringp(v))
              continue;

            from_dir = _trim(k);
            to_ref = _trim(v);

            if (from_dir == "" || to_ref == "")
              continue;

            if (to_ref[0] == '/')
              to_ep = normalize_endpoint(to_ref);
            else {
              if (!room_ids[to_ref])
                continue;

              to_ep = _wilderness_endpoint_from_id(to_ref);
            }

            if (to_ep == "")
              continue;

            pair = pair_key(from_ep, to_ep);
            def = pair_defs[pair];

            if (!mapp(def))
              def = ([ ]);

            if (!mapp(def["link"]))
              def["link"] = ([ ]);

            def["link"][from_ep] = from_dir;
            opposite_dir = _opposite_direction(from_dir);

            if (opposite_dir != "" && !stringp(def["link"][to_ep]))
              def["link"][to_ep] = opposite_dir;

            if (!stringp(def["source"]) || def["source"] == "")
              def["source"] = source_file;

            pair_defs[pair] = def;
          }
        }
      }

      j += 1;
    }

    i += 1;
  }

  foreach (mixed key, mixed link_def in pair_defs) {
    string *eps;

    if (!mapp(link_def))
      continue;

    if (_definitions[key])
      continue;

    eps = endpoints_from_key(key);

    if (sizeof(eps) != 2)
      continue;

    define_link(eps[0], eps[1], link_def);
  }
}

/* Normalize absolute endpoint path */
string normalize_endpoint(string value) {
  value = _trim(value);

  if (value == "") return "";

  /* No .c suffix in canonical endpoint IDs */
  if (sizeof(value) > 2 && value[<2..<1] == ".c")
    value = value[0..<3];

  if (value[0] != '/')
    value = "/" + value;

  /* Collapse accidental double slashes (lightweight) */
  while (strsrch(value, "//") != -1)
    value = replace_string(value, "//", "/");

  return value;
}

/* Normalize area prefix (must be absolute directory) */
string normalize_prefix(string prefix) {
  prefix = normalize_endpoint(prefix);

  if (prefix == "") return "";

  /* Ensure trailing slash so "prefix + rel" is safe */
  if (prefix[<1] != '/')
    prefix += "/";

  return prefix;
}

/* Resolve a possibly-relative endpoint using a prefix */
string resolve_endpoint(string endpoint_ref, string prefix) {
  string trimmed;

  trimmed = _trim(endpoint_ref);

  if (trimmed == "") return "";

  /* Absolute passes through */
  if (trimmed[0] == '/')
    return normalize_endpoint(trimmed);

  prefix = normalize_prefix(prefix);

  if (prefix == "") return "";

  return normalize_endpoint(prefix + trimmed);
}

/*
 * Order-independent key: Link(A,B) == Link(B,A)
 */
string pair_key(string a, string b) {
  return (a <= b) ? (a + "|" + b) : (b + "|" + a);
}

/* Parse endpoints back out of a pair key (for introspection) */
string *endpoints_from_key(string key) {
  int idx;

  idx = strsrch(key, "|");

  if (idx == -1) return ({ "", "" });

  return ({ key[0..idx-1], key[idx+1..] });
}

/* Index maintenance: room -> pair keys */
void index_pair_for_room(string room, string key) {
  string *arr;

  if (!stringp(room) || room == "" || !stringp(key) || key == "")
    return;

  arr = _links_by_room[room];

  if (!pointerp(arr)) arr = ({ });

  /* avoid duplicates */
  if (member_array(key, arr) == -1)
    arr += ({ key });

  _links_by_room[room] = arr;
}

/* ------------------------------------------------------------ */
/* Definition API (authoritative)
 * ------------------------------------------------------------ */

/*
 * Define a link by endpoints (absolute).
 *
 * definition may contain:
 *   "type"      : string (path to link prefab/class, default /core/link)
 *   "gate"      : gateObjOrId  (recommended: id string)
 *   "gates"     : ({ gateObjOrId, ... })   (legacy; first entry used)
 *   "one_way"   : ([ "from": <endpoint>, "to": <endpoint> ])  (optional)
 *   "link"      : ([ endpointAbs : "east", endpointAbs : "west" ]) (optional)
 *   other Link-specific config
 *
 * Once defined, cannot be redefined.
 */
int define_link(string env_a, string env_b, mapping definition) {
  string a, b, key, source;
  mapping dirs;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);
  source = _definition_source(definition);

  if (_definitions[key]) {
    /* Do not silently redefine topology */
    /* Use your own logging/printf facility if preferred */
    write(
      "LINK_D: Duplicate link for endpoints " + a + " <-> " + b + ".\n" +
      "  First: " + _format_definition_ref(key, _definitions[key]) + "\n" +
      "  Duplicate from " + source + "\n"
    );

    return 0;
  }

  if (!mapp(definition)) definition = ([]);

  /* Normalize dirs mapping keys if present (must be absolute) */
  if (mapp(definition["link"])) {
    dirs = ([ ]);

    foreach (mixed k, mixed v in definition["link"]) {
      if (!stringp(k) || !stringp(v)) continue;

      if (_trim(v) == "") continue;

      dirs[ normalize_endpoint(k) ] = _trim(v);
    }

    definition["link"] = dirs;
  }

  /* Normalize appearance mapping keys if present */
  if (mapp(definition["appearances"])) {
    mapping appearances;

    appearances = ([ ]);

    foreach (mixed k, mixed v in definition["appearances"]) {
      if (!stringp(k) || !stringp(v)) continue;

      if (_trim(v) == "") continue;

      appearances[ normalize_endpoint(k) ] = _trim(v);
    }

    definition["appearances"] = appearances;
  }

  /* Direction label collisions are hard errors (per endpoint) */
  if (mapp(definition["link"])) {
    mapping claims;

    foreach (mixed k, mixed v in definition["link"]) {
      string endpoint, label, existing_key;
      mapping existing_def;
      string existing_ref;

      if (!stringp(k) || !stringp(v))
        continue;

      endpoint = normalize_endpoint(k);
      label = _trim(v);

      if (endpoint == "" || label == "")
        continue;

      claims = _dir_claims[endpoint];

      if (!mapp(claims))
        claims = ([ ]);

      existing_key = claims[label];

      if (stringp(existing_key) && existing_key != "") {
        existing_def = _definitions[existing_key];
        existing_ref = _format_definition_ref(existing_key, existing_def);

        write(
          "LINK_D: Direction label collision at " + endpoint + ".\n" +
          "  Label '" + label + "' already claimed by " + existing_ref + "\n" +
          "  Duplicate from " + source + "\n"
        );

        return 0;
      }
    }
  }

  /* Normalize one_way endpoints if present */
  if (mapp(definition["one_way"])) {
    mapping ow = definition["one_way"];
    string from = normalize_endpoint(ow["from"]);
    string to   = normalize_endpoint(ow["to"]);

    if (from != "" && to != "")
      definition["one_way"] = ([ "from": from, "to": to ]);
    else
      map_delete(definition, "one_way");
  }

  _definitions[key] = definition;

  /* Index the pair against both endpoints (for discovery) */
  index_pair_for_room(a, key);
  index_pair_for_room(b, key);

  /* Record direction label claims once accepted */
  if (mapp(definition["link"])) {
    mapping claims;

    foreach (mixed k, mixed v in definition["link"]) {
      string endpoint, label;

      if (!stringp(k) || !stringp(v))
        continue;

      endpoint = normalize_endpoint(k);
      label = _trim(v);

      if (endpoint == "" || label == "")
        continue;

      claims = _dir_claims[endpoint];

      if (!mapp(claims))
        claims = ([ ]);

      claims[label] = key;
      _dir_claims[endpoint] = claims;
    }
  }

  return 1;
}

/* ------------------------------------------------------------ */
/* JSON loading (area-scoped)
 * ------------------------------------------------------------ */

/*
 * Load and register links from a JSON file.
 *
 * Expected:
 *   area_prefix : string (optional but recommended)
 *   links       : array of link objects
 *
 * Each link object may contain:
 *   rooms : [a, b] (optional; inferred from dirs when omitted)
 *   dirs  : { a: "east", b: "west" } (required for inference)
 *   type, gate, one_way, ... (optional)
 *
 * Relative room refs are resolved against area_prefix.
 * If rooms are omitted, endpoints are inferred from dirs keys.
 */
int load_json(string file) {
  string raw, prefix;
  mapping data;
  mixed links_arr;
  int i, ok;

  raw = read_json_file(file);

  if (!stringp(raw)) {
    write("LINK_D: Unable to read JSON file: " + file + "\n");

    return 0;
  }

  data = parse_json(raw);

  if (!mapp(data)) {
    write("LINK_D: Invalid JSON in: " + file + "\n");

    return 0;
  }

  prefix = "";

  if (stringp(data["area_prefix"]))
    prefix = normalize_prefix(data["area_prefix"]);

  links_arr = data["links"];

  if (!pointerp(links_arr)) {
    write("LINK_D: JSON missing 'links' array in: " + file + "\n");

    return 0;
  }

  ok = 1;

  for (i = 0; i < sizeof(links_arr); i++) {
    mapping def;
    mixed rooms;
    string *dir_keys;
    string a_ref, b_ref, a, b;
    mapping dirs_in, dirs_abs;
    mapping appearances_in, appearances_abs;
    string source;

    def = links_arr[i];

    if (!mapp(def)) {
      write("LINK_D: Malformed link entry (not mapping) in " + file + "\n");

      ok = 0;

      continue;
    }

    rooms = def["rooms"];
    dirs_in = def["link"];
    appearances_in = def["appearances"];
    dir_keys = 0;
    a_ref = "";
    b_ref = "";

    if (pointerp(rooms) && sizeof(rooms) == 2) {
      a_ref = rooms[0];
      b_ref = rooms[1];
    } else if (mapp(dirs_in)) {
      dir_keys = keys(dirs_in);

      if (sizeof(dir_keys) == 2) {
        a_ref = dir_keys[0];
        b_ref = dir_keys[1];
      }
    }

    if (!stringp(a_ref) || !stringp(b_ref)) {
      write("LINK_D: Link endpoints must be defined by 'rooms' or 'dirs' in " + file + "\n");

      ok = 0;

      continue;
    }

    a = resolve_endpoint(a_ref, prefix);
    b = resolve_endpoint(b_ref, prefix);

    if (a == "" || b == "") {
      write("LINK_D: Could not resolve endpoints in " + file + "\n");

      ok = 0;

      continue;
    }

    /* Resolve dirs mapping keys the same way rooms resolve */
    dirs_abs = 0;
    if (mapp(dirs_in)) {
      dirs_abs = ([ ]);

      foreach (mixed k, mixed v in dirs_in) {
        string kref, kabs;

	if (!stringp(k) || !stringp(v)) continue;

	kref = k;
        kabs = resolve_endpoint(kref, prefix);

	if (kabs != "")
          dirs_abs[kabs] = _trim(v);
      }
    }

    /* Resolve appearance mapping keys the same way rooms resolve */
    appearances_abs = 0;
    if (mapp(appearances_in)) {
      appearances_abs = ([ ]);

      foreach (mixed k, mixed v in appearances_in) {
        string kref, kabs;

        if (!stringp(k) || !stringp(v)) continue;

        kref = k;
        kabs = resolve_endpoint(kref, prefix);

        if (kabs != "")
          appearances_abs[kabs] = _trim(v);
      }
    }

    /* Build definition mapping for define_link */
    /* Keep original def but normalize pieces we care about */
    if (mapp(dirs_abs))
      def["link"] = dirs_abs;

    if (mapp(appearances_abs))
      def["appearances"] = appearances_abs;

    source = def["source"];

    if (!stringp(source) || _trim(source) == "")
      def["source"] = file + " link[" + i + "]";

    /* Normalize one_way if it references relative endpoints */
    if (mapp(def["one_way"])) {
      mapping ow = def["one_way"];
      string from = "", to = "";

      if (stringp(ow["from"])) from = resolve_endpoint(ow["from"], prefix);

      if (stringp(ow["to"]))   to   = resolve_endpoint(ow["to"], prefix);

      if (from != "" && to != "")
        def["one_way"] = ([ "from": from, "to": to ]);
      else
        map_delete(def, "one_way");
    }

    if (!define_link(a, b, def)) {
      ok = 0;
      /* define_link already wrote a reason */
    }
  }

  return ok;
}

/* ------------------------------------------------------------ */
/* Link instantiation (lazy)
 * ------------------------------------------------------------ */

object _instantiate_link(string a, string b, mapping def) {
  object link;
  mixed gate;

  if (mapp(def) && stringp(def["type"]) && _trim(def["type"]) != "")
    link = new(def["type"]);
  else
    link = new("/core/link");

  link->set_endpoints(a, b);

  /* Optional explicit directionality */
  if (mapp(def) && mapp(def["one_way"])) {
    string from = normalize_endpoint(def["one_way"]["from"]);
    string to   = normalize_endpoint(def["one_way"]["to"]);

    if (from != "" && to != "")
      link->set_one_way(from, to);
  }

  /*
   * Gate (single)
   * Recommended: store gate IDs (strings) in def["gate"] and let the Link
   * ask GATE_D when traversed. But we also accept actual gate objects.
   */
  gate = 0;

  if (mapp(def)) {
    if (objectp(def["gate"]) || stringp(def["gate"]))
      gate = def["gate"];
    else if (pointerp(def["gates"]) && sizeof(def["gates"])) {
      gate = def["gates"][0];

      if (sizeof(def["gates"]) > 1)
        write(
          "LINK_D: Link " + a + " <-> " + b +
          " defines multiple gates; using the first.\n"
        );
    }
  }

  if (objectp(gate)) {
    link->add_gate(gate);
  } else if (stringp(gate) && _trim(gate) != "") {
    /* Optional: Link can treat strings as gate IDs */
    if (function_exists("add_gate_id", link))
      link->add_gate_id(_trim(gate));
    else {
      /* Fallback: store gate ID on the link if it supports metadata */
      if (function_exists("set_meta", link))
        link->set_meta("gate_id", _trim(gate));
    }
  }

  /* Pass through "link" if the Link cares (optional) */
  if (mapp(def) && mapp(def["link"])) {
    if (function_exists("set_dirs", link))
      link->set_dirs(def["link"]);
    else if (function_exists("set_meta", link))
      link->set_meta("link", def["link"]);
  }

  if (mapp(def) && stringp(def["appearance"]) && _trim(def["appearance"]) != "") {
    if (function_exists("set_appearance", link))
      link->set_appearance(_trim(def["appearance"]));
    else if (function_exists("set_meta", link))
      link->set_meta("appearance", _trim(def["appearance"]));
  }

  if (mapp(def) && mapp(def["appearances"])) {
    if (function_exists("set_appearances", link))
      link->set_appearances(def["appearances"]);
    else if (function_exists("set_meta", link))
      link->set_meta("appearances", def["appearances"]);
  }

  return link;
}

/* ------------------------------------------------------------ */
/* Discovery API (rooms call this)
 * ------------------------------------------------------------ */

/*
 * Get (or lazily create) the Link connecting two endpoints.
 * Never loads environments.
 */
object get_link(string env_a, string env_b) {
  string a, b, key;
  object link;
  mapping def;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);

  link = _links[key];

  if (objectp(link)) return link;

  def = _definitions[key];

  if (!mapp(def)) {
    write("LINK_D: Undefined link requested: " + key + "\n");

    return 0;
  }

  link = _instantiate_link(a, b, def);
  _links[key] = link;

  return link;
}

/*
 * Query without instantiating.
 */
object link(string env_a, string env_b) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);

  return _links[key];
}

/* Query whether a definition exists (no instantiation) */
int has_definition(string env_a, string env_b) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);

  return mapp(_definitions[key]);
}

/* ------------------------------------------------------------ */
/* Room-centric discovery
 * ------------------------------------------------------------ */

/*
 * Return pair keys for links incident to a room.
 * (Does not instantiate links.)
 */
string *defined_pairs_for_room(string room) {
  room = normalize_endpoint(room);

  if (room == "") return ({ });

  return _links_by_room[room] || ({ });
}

/*
 * Return instantiated Link objects incident to a room.
 * (Instantiates any defined-but-not-instantiated links touching this room.)
 */
object *links_for_room(string room) {
  string *keys;
  object *out;
  int i;

  room = normalize_endpoint(room);

  if (room == "") return ({ });

  keys = _links_by_room[room] || ({ });
  out = ({ });

  for (i = 0; i < sizeof(keys); i++) {
    string key = keys[i];
    string *eps;

    if (objectp(_links[key])) {
      out += ({ _links[key] });

      continue;
    }

    /* instantiate via endpoints */
    eps = endpoints_from_key(key);

    if (sizeof(eps) != 2) continue;

    /* get_link will validate def exists */
    if (get_link(eps[0], eps[1]))
      out += ({ _links[key] });
  }

  return out;
}

/*
 * Return mapping direction -> Link for a given room.
 * Only includes links that provide a direction label for that room.
 * (Instantiates incident links as needed.)
 */
mapping links_by_direction_for_room(string room) {
  object *ls;
  mapping out;
  int i;

  room = normalize_endpoint(room);
  out = ([ ]);

  ls = links_for_room(room);

  for (i = 0; i < sizeof(ls); i++) {
    object link = ls[i];
    mapping dirs;
    string dir;

    /* Prefer Link API; fallback to metadata if present */
    if (objectp(link) && function_exists("dirs", link))
      dirs = link->dirs();
    else if (objectp(link) && function_exists("meta", link))
      dirs = link->meta("link");

    if (!mapp(dirs)) continue;

    dir = dirs[room];

    if (!stringp(dir) || _trim(dir) == "") continue;

    out[_trim(dir)] = link;
  }

  return out;
}

/* ------------------------------------------------------------ */
/* Introspection / debugging
 * ------------------------------------------------------------ */

string *defined_link_pairs() {
  return keys(_definitions);
}

string *instantiated_link_pairs() {
  return keys(_links);
}

mapping definition(string env_a, string env_b) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);

  return _definitions[key];
}
