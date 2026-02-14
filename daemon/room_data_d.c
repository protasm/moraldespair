mapping room_data_by_path;
mapping virtual_specs_by_path;
mapping room_paths_by_source_dir;
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

int should_scan_json_file(string file) {
  string lower_name;

  if (!stringp(file) || file == "")
    return 0;

  lower_name = lower_case(file);

  if (strsrch(lower_name, "link") != -1)
    return 0;

  if (strsrch(lower_name, "/chapter/") != 0 &&
      strsrch(lower_name, "/maps/") != 0)
    return 0;

  return 1;
}

void index_room_entry(string json_file, mapping json_root, mapping room_entry) {
  string room_id, room_file, source_dir, room_path;
  mapping paths_by_id;
  string template;

  if (!mapp(room_entry))
    return;

  room_id = room_entry["id"];
  room_file = room_entry["file"];
  source_dir = json_root["source_dir"];
  source_dir = normalize_path(source_dir);
  room_path = "";

  if (stringp(room_file) && room_file != "")
    room_path = normalize_path(room_file);
  else if (stringp(source_dir) && source_dir != "" && stringp(room_id) && room_id != "")
    room_path = normalize_path(source_dir + "/" + room_id);
  else if (strsrch(json_file, "/area/wilderness/") != -1 &&
           stringp(room_id) && room_id != "")
    room_path = "/chapter/prologue/std/wilderness_room#" + room_id;

  if (room_path == "")
    return;

  if (mapp(room_data_by_path[room_path]))
    return;

  room_data_by_path[room_path] = room_entry;
  template = "data_room";

  if (strsrch(room_path, "/chapter/prologue/std/wilderness_room#") == 0)
    template = "wilderness_room";

  virtual_specs_by_path[room_path] = ([
    "template" : template,
    "id" : room_id,
    "path" : room_path,
    "source_json" : json_file
  ]);

  if (stringp(source_dir) && source_dir != "" &&
      stringp(room_id) && room_id != "") {
    paths_by_id = room_paths_by_source_dir[source_dir];

    if (!mapp(paths_by_id))
      paths_by_id = ([]);

    if (!stringp(paths_by_id[room_id]))
      paths_by_id[room_id] = room_path;

    room_paths_by_source_dir[source_dir] = paths_by_id;
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
  string chapter_dir;
  string area_dir;
  string json_file;
  int i, j, k;

  room_data_by_path = ([]);
  virtual_specs_by_path = ([]);
  room_paths_by_source_dir = ([]);
  json_files_loaded = ({ });
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
        area_json_files = get_dir(area_dir + "/*.json");

        if (pointerp(area_json_files)) {
          k = 0;

          while (k < sizeof(area_json_files)) {
            json_file = join_path(area_dir, area_json_files[k]);

            if (should_scan_json_file(json_file))
              load_room_json(json_file);

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

      if (should_scan_json_file(json_file))
        load_room_json(json_file);

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

  if (mapp(spec))
    return copy(spec);

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
