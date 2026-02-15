mapping room_data_by_path;
mapping virtual_specs_by_path;
mapping room_paths_by_source_dir;
mapping terrain_catalog_by_chapter_dir;
int loaded, room_count, json_file_count;
string *json_files_loaded;
string last_load_error;

string normalize_path(string path) {
  if (!stringp(path) || path == "")
    return "";

  if (path[0] != '/')
    path = "/" + path;

  if (sizeof(path) > 2 && path[<2..<1] == ".c")
    path = path[0..<3];

  while (strsrch(path, "//") != -1)
    path = replace_string(path, "//", "/");

  return path;
}

string join_path(string base, string entry) {
  if (!stringp(entry) || entry == "")
    return "";

  if (entry[0] == '/')
    return normalize_path(entry);

  if (!stringp(base) || base == "")
    return normalize_path(entry);

  return normalize_path(base + "/" + entry);
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

string area_dir_from_json_file(string json_file) {
  string normalized_file;
  string remaining_path;
  int area_marker_index;
  int area_name_end_index;
  string chapter_name;
  string area_name;

  normalized_file = normalize_path(json_file);

  if (normalized_file == "")
    return "";

  if (strsrch(normalized_file, "/chapter/") != 0)
    return "";

  remaining_path = normalized_file[9..];
  area_marker_index = strsrch(remaining_path, "/area/");

  if (area_marker_index == -1)
    return "";

  chapter_name = remaining_path[0..area_marker_index - 1];
  remaining_path = remaining_path[area_marker_index + 6..];
  area_name_end_index = strsrch(remaining_path, "/");

  if (area_name_end_index == -1)
    return "";

  area_name = remaining_path[0..area_name_end_index - 1];

  if (!stringp(chapter_name) || chapter_name == "")
    return "";

  if (!stringp(area_name) || area_name == "")
    return "";

  return "/chapter/" + chapter_name + "/area/" + area_name;
}

string *sub_area_dirs_from_json(string area_dir) {
  string subareas_file;
  string subareas_raw;
  mixed subareas_parsed;
  mixed sub_areas;
  string *sub_dirs;
  string sub_area;
  string sub_dir;
  int i;

  area_dir = normalize_path(area_dir);

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

string *legacy_room_json_files(string area_dir) {
  string *entries;
  string *json_files;
  string entry;
  string json_file;
  string lower_name;
  int i;

  area_dir = normalize_path(area_dir);

  if (area_dir == "")
    return ({ });

  entries = get_dir(area_dir + "/*.json");

  if (!pointerp(entries))
    return ({ });

  json_files = ({ });
  i = 0;

  while (i < sizeof(entries)) {
    entry = entries[i];

    if (!stringp(entry) || entry == "") {
      i += 1;

      continue;
    }

    json_file = join_path(area_dir, entry);
    lower_name = lower_case(json_file);

    if (lower_name == "") {
      i += 1;

      continue;
    }

    if (sizeof(lower_name) >= 10 && lower_name[<9..] == "/links.json") {
      i += 1;

      continue;
    }

    if (sizeof(lower_name) >= 13 && lower_name[<12..] == "/subareas.json") {
      i += 1;

      continue;
    }

    if (sizeof(lower_name) >= 10 && lower_name[<9..] == "/rooms.json") {
      i += 1;

      continue;
    }

    json_files += ({ json_file });
    i += 1;
  }

  return json_files;
}

string *collect_area_room_json_files(string area_dir, mapping visited_dirs) {
  string rooms_file;
  string *json_files;
  string *legacy_files;
  string *sub_dirs;
  string sub_dir;
  int i;

  area_dir = normalize_path(area_dir);

  if (area_dir == "")
    return ({ });

  if (mapp(visited_dirs) && visited_dirs[area_dir])
    return ({ });

  if (mapp(visited_dirs))
    visited_dirs[area_dir] = 1;

  json_files = ({ });
  rooms_file = join_path(area_dir, "rooms.json");

  if (file_size(rooms_file) > 0)
    json_files += ({ rooms_file });

  legacy_files = legacy_room_json_files(area_dir);

  if (pointerp(legacy_files) && sizeof(legacy_files))
    json_files += legacy_files;

  sub_dirs = sub_area_dirs_from_json(area_dir);
  i = 0;

  while (i < sizeof(sub_dirs)) {
    sub_dir = sub_dirs[i];
    json_files += collect_area_room_json_files(sub_dir, visited_dirs);
    i += 1;
  }

  return json_files;
}

string chapter_dir_from_area_dir(string area_dir) {
  string chapter_name;
  string area_name;

  area_dir = normalize_path(area_dir);

  if (area_dir == "")
    return "";

  chapter_name = "";
  area_name = "";

  if (sscanf(area_dir, "/chapter/%s/area/%s", chapter_name, area_name) != 2)
    return "";

  if (!stringp(chapter_name) || chapter_name == "")
    return "";

  return "/chapter/" + chapter_name;
}

mapping terrain_catalog_for_area_dir(string area_dir) {
  mapping terrain_catalog;
  mixed parsed_json;
  string chapter_dir;
  string terrain_file;
  string terrain_contents;

  chapter_dir = chapter_dir_from_area_dir(area_dir);

  if (chapter_dir == "")
    return 0;

  terrain_catalog = terrain_catalog_by_chapter_dir[chapter_dir];

  if (mapp(terrain_catalog))
    return terrain_catalog;

  terrain_file = chapter_dir + "/std/terrain.json";

  if (file_size(terrain_file) <= 0)
    return 0;

  terrain_contents = read_json_file(terrain_file);

  if (!stringp(terrain_contents) || terrain_contents == "")
    return 0;

  parsed_json = parse_json(terrain_contents);

  if (!mapp(parsed_json))
    return 0;

  terrain_catalog = parsed_json;
  terrain_catalog_by_chapter_dir[chapter_dir] = terrain_catalog;

  return terrain_catalog;
}

void index_room_entry(string json_file, mapping json_root, mapping room_entry) {
  string room_id, room_file, source_dir, source_root, room_path, area_dir, terrain_code;
  mapping paths_by_id;
  mapping indexed_room_data;
  mapping terrain_catalog;
  mapping terrain_info;

  if (!mapp(room_entry))
    return;

  indexed_room_data = copy(room_entry);
  room_id = room_entry["id"];
  room_file = room_entry["file"];
  source_dir = json_root["source_dir"];
  source_dir = normalize_path(source_dir);
  source_root = "";
  room_path = "";
  area_dir = area_dir_from_json_file(json_file);

  if (stringp(room_file) && room_file != "")
    room_path = normalize_path(room_file);
  else if (stringp(source_dir) && source_dir != "" && stringp(room_id) && room_id != "")
    room_path = normalize_path(source_dir + "/" + room_id);
  else if (stringp(area_dir) && area_dir != "" && stringp(room_id) && room_id != "")
    room_path = normalize_path(area_dir + "/room/" + room_id);

  source_root = source_dir;

  if ((!stringp(source_root) || source_root == "") &&
      stringp(area_dir) && area_dir != "")
    source_root = area_dir;

  if (room_path == "")
    return;

  if (mapp(room_data_by_path[room_path]))
    return;

  terrain_code = indexed_room_data["terrain"];

  if (stringp(terrain_code) && terrain_code != "" &&
      stringp(area_dir) && area_dir != "") {
    terrain_catalog = terrain_catalog_for_area_dir(area_dir);

    if (mapp(terrain_catalog))
      terrain_info = terrain_catalog[terrain_code];

    if (!mapp(terrain_info) && mapp(terrain_catalog))
      terrain_info = terrain_catalog["default"];

    if (mapp(terrain_info)) {
      if (!stringp(indexed_room_data["short"]) && stringp(terrain_info["short"]))
        indexed_room_data["short"] = terrain_info["short"];

      if (!stringp(indexed_room_data["long"]) &&
          !pointerp(indexed_room_data["long"])) {
        if (pointerp(terrain_info["long"]) || stringp(terrain_info["long"]))
          indexed_room_data["long"] = terrain_info["long"];
      }

      if (!intp(indexed_room_data["traverse_cost"]) &&
          intp(terrain_info["traverse_cost"]))
        indexed_room_data["traverse_cost"] = terrain_info["traverse_cost"];

      if (!stringp(indexed_room_data["traverse_failure"]) &&
          stringp(terrain_info["traverse_failure"]))
        indexed_room_data["traverse_failure"] = terrain_info["traverse_failure"];
    }
  }

  room_data_by_path[room_path] = indexed_room_data;

  virtual_specs_by_path[room_path] = ([
    "template" : "vroom",
    "id" : room_id,
    "path" : room_path,
    "source_json" : json_file
  ]);

  if (stringp(source_root) && source_root != "" &&
      stringp(room_id) && room_id != "") {
    paths_by_id = room_paths_by_source_dir[source_root];

    if (!mapp(paths_by_id))
      paths_by_id = ([]);

    if (!stringp(paths_by_id[room_id]))
      paths_by_id[room_id] = room_path;

    room_paths_by_source_dir[source_root] = paths_by_id;
  }

  return;
}

void load_room_json(string json_file) {
  mixed parsed_json;
  mixed rooms;
  mapping json_root;
  mapping room_entry;
  string json_contents;
  int i;

  if (!stringp(json_file) || json_file == "")
    return;

  json_contents = read_json_file(json_file);

  if (!stringp(json_contents) || json_contents == "")
    return;

  parsed_json = parse_json(json_contents);

  if (!mapp(parsed_json))
    return;

  json_root = parsed_json;
  rooms = json_root["rooms"];

  if (!pointerp(rooms))
    return;

  json_files_loaded += ({ json_file });
  i = 0;

  while (i < sizeof(rooms)) {
    room_entry = rooms[i];
    index_room_entry(json_file, json_root, room_entry);

    i += 1;
  }

  return;
}

void load_room_data() {
  string *chapter_dirs;
  string *area_dirs;
  string *area_json_files;
  string *map_json_files;
  mapping visited_dirs;
  mapping loaded_json_files;
  string chapter_dir;
  string area_dir;
  string json_file;
  int i, j, k;

  room_data_by_path = ([]);
  virtual_specs_by_path = ([]);
  room_paths_by_source_dir = ([]);
  terrain_catalog_by_chapter_dir = ([]);
  json_files_loaded = ({ });
  loaded_json_files = ([ ]);
  visited_dirs = ([ ]);
  room_count = 0;
  json_file_count = 0;
  last_load_error = 0;

  chapter_dirs = get_dir("/chapter/*");

  if (!pointerp(chapter_dirs)) {
    loaded = 1;
    last_load_error = "get_dir returned no chapter directory list";

    return;
  }

  i = 0;

  while (i < sizeof(chapter_dirs)) {
    chapter_dir = join_path("/chapter", chapter_dirs[i]);
    area_dirs = get_dir(chapter_dir + "/area/*");

    if (pointerp(area_dirs)) {
      j = 0;

      while (j < sizeof(area_dirs)) {
        area_dir = join_path(chapter_dir + "/area", area_dirs[j]);
        area_json_files = collect_area_room_json_files(area_dir, visited_dirs);

        if (pointerp(area_json_files)) {
          k = 0;

          while (k < sizeof(area_json_files)) {
            json_file = area_json_files[k];

            if (stringp(json_file) && json_file != "" &&
                !loaded_json_files[json_file]) {
              loaded_json_files[json_file] = 1;
              load_room_json(json_file);
            }

            k += 1;
          }
        }

        j += 1;
      }
    }

    i += 1;
  }

  map_json_files = get_dir("/maps/*.json");

  if (pointerp(map_json_files)) {
    i = 0;

    while (i < sizeof(map_json_files)) {
      json_file = join_path("/maps", map_json_files[i]);

      if (stringp(json_file) && json_file != "" &&
          !loaded_json_files[json_file]) {
        loaded_json_files[json_file] = 1;
        load_room_json(json_file);
      }

      i += 1;
    }
  }

  room_count = sizeof(keys(room_data_by_path));
  json_file_count = sizeof(json_files_loaded);
  loaded = 1;

  return;
}

void create() {
  loaded = 0;

  load_room_data();

  return;
}

void reload_room_data() {
  loaded = 0;

  load_room_data();

  return;
}

int room_exists(string room_path) {
  room_path = normalize_path(room_path);

  if (room_path == "")
    return 0;

  if (mapp(room_data_by_path[room_path]))
    return 1;

  return 0;
}

mapping room_data(string room_path) {
  mapping room;

  room_path = normalize_path(room_path);

  if (room_path == "")
    return 0;

  room = room_data_by_path[room_path];

  if (!mapp(room))
    return 0;

  return room;
}

mapping virtual_spec(string room_path) {
  mapping spec;

  room_path = normalize_path(room_path);

  if (room_path == "")
    return 0;

  spec = virtual_specs_by_path[room_path];

  if (!mapp(spec))
    return 0;

  return spec;
}

mapping resolve_room_request(string requested_path) {
  string normalized_path;
  string area_source_dir;
  string room_id;
  string resolved_room_path;
  string custom_room_path;
  mapping paths_by_id;
  mapping spec;

  normalized_path = normalize_path(requested_path);

  if (normalized_path == "")
    return 0;

  spec = virtual_specs_by_path[normalized_path];

  if (mapp(spec)) {
    spec = copy(spec);
    area_source_dir = "";
    room_id = "";

    if (sscanf(normalized_path, "%s/room/%s", area_source_dir, room_id) == 2) {
      area_source_dir = normalize_path(area_source_dir);

      if (area_source_dir != "")
        spec["custom_path"] = normalize_path(area_source_dir + "/" + room_id);
    }

    return spec;
  }

  area_source_dir = "";
  room_id = "";

  if (sscanf(normalized_path, "%s/room/%s", area_source_dir, room_id) != 2)
    return 0;

  area_source_dir = normalize_path(area_source_dir);

  if (area_source_dir == "")
    return 0;

  paths_by_id = room_paths_by_source_dir[area_source_dir];

  if (!mapp(paths_by_id))
    return 0;

  resolved_room_path = paths_by_id[room_id];

  if (!stringp(resolved_room_path) || resolved_room_path == "")
    return 0;

  spec = virtual_specs_by_path[resolved_room_path];

  if (!mapp(spec))
    return 0;

  spec = copy(spec);
  custom_room_path = normalize_path(area_source_dir + "/" + room_id);
  spec["custom_path"] = custom_room_path;

  return spec;
}

mapping debug_status() {
  return ([
    "loaded" : loaded,
    "room_count" : room_count,
    "json_file_count" : json_file_count,
    "json_files_loaded" : json_files_loaded,
    "last_load_error" : last_load_error
  ]);
}
