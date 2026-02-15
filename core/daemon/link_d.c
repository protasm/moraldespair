/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/link_d.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "link_d.h"
 */

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
string *collect_area_link_files(string area_dir, mapping visited_dirs);
int load_json(string file);

/* ------------------------------------------------------------ */

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  string *chapter_dirs;
  string *area_dirs;
  string *area_link_files;
  mapping visited_dirs;
  mapping loaded_files;
  string chapter_dir;
  string area_dir;
  string link_file;
  int i, j, k;

  _links         = ([]);
  _definitions   = ([]);
  _links_by_room = ([]);
  _dir_claims    = ([]);
  chapter_dirs = get_dir("/chapter/*");
  visited_dirs = ([ ]);
  loaded_files = ([ ]);

  if (!pointerp(chapter_dirs))
    return;

  i = 0;

  while (i < sizeof(chapter_dirs)) {
    chapter_dir = normalize_endpoint("/chapter/" + chapter_dirs[i]);
    area_dirs = get_dir(chapter_dir + "/area/*");

    if (pointerp(area_dirs)) {
      j = 0;

      while (j < sizeof(area_dirs)) {
        area_dir = normalize_endpoint(chapter_dir + "/area/" + area_dirs[j]);
        area_link_files = collect_area_link_files(area_dir, visited_dirs);
        k = 0;

        while (k < sizeof(area_link_files)) {
          link_file = area_link_files[k];

          if (stringp(link_file) && link_file != "" && !loaded_files[link_file]) {
            loaded_files[link_file] = 1;
            load_json(link_file);
          }

          k += 1;
        }

        j += 1;
      }
    }

    i += 1;
  }
}

/* ------------------------------------------------------------ */
/* Utilities
 * ------------------------------------------------------------ */

/* Method Summary:
 * Purpose:
 *   Handles _trim for this object.
 * Parameters:
 *   - string s
 * Approach:
 *   Validates inputs and executes explicit local logic for _trim.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from _trim.
 */
string _trim(string s) {
  if (!stringp(s)) return "";

  return trim(s);
}

/* Method Summary:
 * Purpose:
 *   Handles _definition_source for this object.
 * Parameters:
 *   - mapping definition
 * Approach:
 *   Validates inputs and executes explicit local logic for _definition_source.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from _definition_source.
 */
string _definition_source(mapping definition) {
  string source;

  if (!mapp(definition))
    return "unknown";

  source = definition["source"];

  if (!stringp(source) || _trim(source) == "")
    return "unknown";

  return _trim(source);
}

/* Method Summary:
 * Purpose:
 *   Handles _format_definition_ref for this object.
 * Parameters:
 *   - string key, mapping definition
 * Approach:
 *   Validates inputs and executes explicit local logic for _format_definition_ref.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from _format_definition_ref.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles parse_json for this object.
 * Parameters:
 *   - string raw
 * Approach:
 *   Validates inputs and executes explicit local logic for parse_json.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mixed result from parse_json.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles read_json_file for this object.
 * Parameters:
 *   - string file
 * Approach:
 *   Validates inputs and executes explicit local logic for read_json_file.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from read_json_file.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles join_path for this object.
 * Parameters:
 *   - string base, string entry
 * Approach:
 *   Validates inputs and executes explicit local logic for join_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from join_path.
 */
string join_path(string base, string entry) {
  if (!stringp(entry) || entry == "")
    return "";

  if (entry[0] == '/')
    return normalize_endpoint(entry);

  if (!stringp(base) || base == "")
    return normalize_endpoint(entry);

  return normalize_endpoint(base + "/" + entry);
}

/* Method Summary:
 * Purpose:
 *   Handles sub_area_dirs_from_json for this object.
 * Parameters:
 *   - string area_dir
 * Approach:
 *   Validates inputs and executes explicit local logic for sub_area_dirs_from_json.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from sub_area_dirs_from_json.
 */
string *sub_area_dirs_from_json(string area_dir) {
  string subareas_file;
  string subareas_raw;
  mixed subareas_parsed;
  mixed sub_areas;
  string *sub_dirs;
  string sub_area;
  string sub_dir;
  int i;

  area_dir = normalize_endpoint(area_dir);

  if (area_dir == "")
    return ({ });

  subareas_file = join_path(area_dir, "subareas.json");

  if (file_size(subareas_file) <= 0)
    return ({ });

  subareas_raw = read_json_file(subareas_file);

  if (!stringp(subareas_raw) || subareas_raw == "")
    return ({ });

  subareas_parsed = parse_json(subareas_raw);

  if (!mapp(subareas_parsed))
    return ({ });

  sub_areas = subareas_parsed["sub_areas"];

  if (!pointerp(sub_areas))
    return ({ });

  sub_dirs = ({ });
  i = 0;

  while (i < sizeof(sub_areas)) {
    sub_area = sub_areas[i];

    if (!stringp(sub_area) || sub_area == "") {
      i += 1;

      continue;
    }

    sub_dir = join_path(area_dir, sub_area);

    if (file_size(sub_dir) == -2)
      sub_dirs += ({ sub_dir });

    i += 1;
  }

  return sub_dirs;
}

/* Method Summary:
 * Purpose:
 *   Handles collect_area_link_files for this object.
 * Parameters:
 *   - string area_dir, mapping visited_dirs
 * Approach:
 *   Validates inputs and executes explicit local logic for collect_area_link_files.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from collect_area_link_files.
 */
string *collect_area_link_files(string area_dir, mapping visited_dirs) {
  string links_file;
  string *link_files;
  string *sub_dirs;
  string sub_dir;
  int i;

  area_dir = normalize_endpoint(area_dir);

  if (area_dir == "")
    return ({ });

  if (mapp(visited_dirs) && visited_dirs[area_dir])
    return ({ });

  if (mapp(visited_dirs))
    visited_dirs[area_dir] = 1;

  link_files = ({ });
  links_file = join_path(area_dir, "links.json");

  if (file_size(links_file) > 0)
    link_files += ({ links_file });

  sub_dirs = sub_area_dirs_from_json(area_dir);
  i = 0;

  while (i < sizeof(sub_dirs)) {
    sub_dir = sub_dirs[i];
    link_files += collect_area_link_files(sub_dir, visited_dirs);
    i += 1;
  }

  return link_files;
}

/* Method Summary:
 * Purpose:
 *   Handles _opposite_direction for this object.
 * Parameters:
 *   - string dir
 * Approach:
 *   Validates inputs and executes explicit local logic for _opposite_direction.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from _opposite_direction.
 */
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

/* Normalize absolute endpoint path */
/* Method Summary:
 * Purpose:
 *   Handles normalize_endpoint for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_endpoint.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_endpoint.
 */
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
/* Method Summary:
 * Purpose:
 *   Handles normalize_prefix for this object.
 * Parameters:
 *   - string prefix
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_prefix.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_prefix.
 */
string normalize_prefix(string prefix) {
  prefix = normalize_endpoint(prefix);

  if (prefix == "") return "";

  /* Ensure trailing slash so "prefix + rel" is safe */
  if (prefix[<1] != '/')
    prefix += "/";

  return prefix;
}

/* Method Summary:
 * Purpose:
 *   Handles parent_dir_from_file for this object.
 * Parameters:
 *   - string file
 * Approach:
 *   Validates inputs and executes explicit local logic for parent_dir_from_file.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from parent_dir_from_file.
 */
string parent_dir_from_file(string file) {
  string normalized_file;
  string parent_dir;
  string base_name;

  normalized_file = normalize_endpoint(file);

  if (normalized_file == "")
    return "";

  parent_dir = "";
  base_name = "";

  if (sscanf(normalized_file, "%s/%s", parent_dir, base_name) != 2)
    return "";

  parent_dir = normalize_endpoint(parent_dir);

  return parent_dir;
}

/* Method Summary:
 * Purpose:
 *   Handles inferred_prefix_from_rooms_json for this object.
 * Parameters:
 *   - string link_file
 * Approach:
 *   Validates inputs and executes explicit local logic for inferred_prefix_from_rooms_json.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from inferred_prefix_from_rooms_json.
 */
string inferred_prefix_from_rooms_json(string link_file) {
  string parent_dir;
  string source_file;
  string legacy_rooms_file;
  string area_name;
  string *path_parts;
  string json_raw;
  mapping json_data;
  string inferred_prefix;

  parent_dir = parent_dir_from_file(link_file);

  if (parent_dir == "")
    return "";

  source_file = join_path(parent_dir, "rooms.json");

  if (file_size(source_file) <= 0) {
    area_name = "";
    path_parts = explode(parent_dir, "/");

    if (pointerp(path_parts) && sizeof(path_parts))
      area_name = path_parts[<1];

    if (stringp(area_name) && area_name != "") {
      legacy_rooms_file = join_path(parent_dir, area_name + ".json");

      if (file_size(legacy_rooms_file) > 0)
        source_file = legacy_rooms_file;
    }
  }

  if (file_size(source_file) <= 0)
    return "";

  json_raw = read_json_file(source_file);

  if (!stringp(json_raw) || json_raw == "")
    return "";

  json_data = parse_json(json_raw);

  if (!mapp(json_data))
    return "";

  inferred_prefix = "";

  if (stringp(json_data["source_dir"]))
    inferred_prefix = normalize_prefix(json_data["source_dir"]);

  if (inferred_prefix == "" && stringp(json_data["area_prefix"]))
    inferred_prefix = normalize_prefix(json_data["area_prefix"]);

  return inferred_prefix;
}

/* Resolve a possibly-relative endpoint using a prefix */
/* Method Summary:
 * Purpose:
 *   Handles resolve_endpoint for this object.
 * Parameters:
 *   - string endpoint_ref, string prefix
 * Approach:
 *   Validates inputs and executes explicit local logic for resolve_endpoint.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from resolve_endpoint.
 */
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
/* Method Summary:
 * Purpose:
 *   Handles pair_key for this object.
 * Parameters:
 *   - string a, string b
 * Approach:
 *   Validates inputs and executes explicit local logic for pair_key.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from pair_key.
 */
string pair_key(string a, string b) {
  return (a <= b) ? (a + "|" + b) : (b + "|" + a);
}

/* Parse endpoints back out of a pair key (for introspection) */
/* Method Summary:
 * Purpose:
 *   Handles endpoints_from_key for this object.
 * Parameters:
 *   - string key
 * Approach:
 *   Validates inputs and executes explicit local logic for endpoints_from_key.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from endpoints_from_key.
 */
string *endpoints_from_key(string key) {
  int idx;

  idx = strsrch(key, "|");

  if (idx == -1) return ({ "", "" });

  return ({ key[0..idx-1], key[idx+1..] });
}

/* Index maintenance: room -> pair keys */
/* Method Summary:
 * Purpose:
 *   Handles index_pair_for_room for this object.
 * Parameters:
 *   - string room, string key
 * Approach:
 *   Validates inputs and executes explicit local logic for index_pair_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from index_pair_for_room.
 */
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
 *   "type"      : string (path to link prefab/class, default /core/link/link)
 *   "gate"      : gateObjOrId  (recommended: id string)
 *   "gates"     : ({ gateObjOrId, ... })   (legacy; first entry used)
 *   "one_way"   : ([ "from": <endpoint>, "to": <endpoint> ])  (optional)
 *   "link"      : ([ endpointAbs : "east", endpointAbs : "west" ]) (optional)
 *   other Link-specific config
 *
 * Once defined, cannot be redefined.
 */
/* Method Summary:
 * Purpose:
 *   Handles define_link for this object.
 * Parameters:
 *   - string env_a, string env_b, mapping definition
 * Approach:
 *   Validates inputs and executes explicit local logic for define_link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from define_link.
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
 *   area_prefix : string (optional)
 *   links       : array of link objects
 *
 * Each link object may contain:
 *   rooms : [a, b] (optional; inferred from dirs when omitted)
 *   dirs  : { a: "east", b: "west" } (required for inference)
 *   type, gate, one_way, ... (optional)
 *
 * Relative room refs are resolved against area_prefix.
 * If area_prefix is omitted, LINK_D attempts to infer it from sibling
 * rooms.json source_dir (or legacy area-name JSON source_dir).
 * If rooms are omitted, endpoints are inferred from dirs keys.
 */
/* Method Summary:
 * Purpose:
 *   Handles load_json for this object.
 * Parameters:
 *   - string file
 * Approach:
 *   Validates inputs and executes explicit local logic for load_json.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from load_json.
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

  if (prefix == "")
    prefix = inferred_prefix_from_rooms_json(file);

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
      write("LINK_D: Link endpoints must be defined by 'rooms' or 'link' in " + file + "\n");

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

/* Method Summary:
 * Purpose:
 *   Handles _instantiate_link for this object.
 * Parameters:
 *   - string a, string b, mapping def
 * Approach:
 *   Validates inputs and executes explicit local logic for _instantiate_link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from _instantiate_link.
 */
object _instantiate_link(string a, string b, mapping def) {
  object link;
  mixed gate;

  if (mapp(def) && stringp(def["type"]) && _trim(def["type"]) != "")
    link = new(def["type"]);
  else
    link = new("/core/link/link");

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
/* Method Summary:
 * Purpose:
 *   Handles get_link for this object.
 * Parameters:
 *   - string env_a, string env_b
 * Approach:
 *   Validates inputs and executes explicit local logic for get_link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from get_link.
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
/* Method Summary:
 * Purpose:
 *   Handles link for this object.
 * Parameters:
 *   - string env_a, string env_b
 * Approach:
 *   Validates inputs and executes explicit local logic for link.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from link.
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
/* Method Summary:
 * Purpose:
 *   Handles has_definition for this object.
 * Parameters:
 *   - string env_a, string env_b
 * Approach:
 *   Validates inputs and executes explicit local logic for has_definition.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from has_definition.
 */
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
/* Method Summary:
 * Purpose:
 *   Handles defined_pairs_for_room for this object.
 * Parameters:
 *   - string room
 * Approach:
 *   Validates inputs and executes explicit local logic for defined_pairs_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from defined_pairs_for_room.
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
/* Method Summary:
 * Purpose:
 *   Handles links_for_room for this object.
 * Parameters:
 *   - string room
 * Approach:
 *   Validates inputs and executes explicit local logic for links_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from links_for_room.
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
/* Method Summary:
 * Purpose:
 *   Handles links_by_direction_for_room for this object.
 * Parameters:
 *   - string room
 * Approach:
 *   Validates inputs and executes explicit local logic for links_by_direction_for_room.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from links_by_direction_for_room.
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

/* Method Summary:
 * Purpose:
 *   Handles defined_link_pairs for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for defined_link_pairs.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from defined_link_pairs.
 */
string *defined_link_pairs() {
  return keys(_definitions);
}

/* Method Summary:
 * Purpose:
 *   Handles instantiated_link_pairs for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for instantiated_link_pairs.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from instantiated_link_pairs.
 */
string *instantiated_link_pairs() {
  return keys(_links);
}

/* Method Summary:
 * Purpose:
 *   Handles definition for this object.
 * Parameters:
 *   - string env_a, string env_b
 * Approach:
 *   Validates inputs and executes explicit local logic for definition.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from definition.
 */
mapping definition(string env_a, string env_b) {
  string a, b, key;

  a = normalize_endpoint(env_a);
  b = normalize_endpoint(env_b);

  if (a == "" || b == "") return 0;

  key = pair_key(a, b);

  return _definitions[key];
}
