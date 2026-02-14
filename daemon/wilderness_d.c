#include "/daemon/wilderness_d.h"

/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
mapping rooms_by_id;
mapping terrain_by_code;
int loaded, room_count;
int map_json_size, terrain_json_size, rooms_array_count, terrain_code_count;
string last_load_error;

void log_preload_status(mixed load_error) {
  string message;
  string preload_result;
  string catch_error_text;

  preload_result = "success";
  catch_error_text = "0";

  if (load_error) {
    preload_result = "failure";
    catch_error_text = save_variable(load_error);
  }

  message = "wilderness_d preload\n";
  message += sprintf("result=%s\n", preload_result);
  message += "map_json_files=/chapter/prologue/area/wilderness/wilderness_nw.json,"
    + "/chapter/prologue/area/wilderness/wilderness_sw.json,"
    + "/chapter/prologue/area/wilderness/wilderness_ne.json,"
    + "/chapter/prologue/area/wilderness/wilderness_se.json\n";
  message += "terrain_json=/chapter/prologue/area/wilderness/wilderness_terrain.json\n";
  message += sprintf("map_json_size=%d\n", map_json_size);
  message += sprintf("terrain_json_size=%d\n", terrain_json_size);
  message += sprintf("rooms_array_count=%d\n", rooms_array_count);
  message += sprintf("room_count=%d\n", room_count);
  message += sprintf("terrain_code_count=%d\n", terrain_code_count);
  message += sprintf("last_load_error=%O\n", last_load_error);
  message += sprintf("catch_error=%s\n", catch_error_text);
  message += "---\n";

  write_file("/log/wilderness_preload", message);

  return;
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

string read_wilderness_file(string file) {
  string chunk, contents;
  string *chunks;
  int size, offset, chunk_size, read_size;
  int line, line_count;
  mixed read_error;

  if (!stringp(file))
    return 0;

  size = file_size(file);

  if (size <= 0)
    return 0;

  chunks = ({ });
  line = 1;
  line_count = 200;
  chunk_size = 2048;
  offset = 0;
  read_size = 0;
  read_error = 0;

  /*
   * Prefer line-based reads to avoid per-call byte transfer limits.
   * If a driver still fails here, fall back to small adaptive byte reads.
   */
  while (1) {
    read_error = catch(chunk = read_file(file, line, line_count));

    if (read_error) {
      last_load_error = "read_file failed for " + file + ": " + read_error;
      chunks = ({ });

      break;
    }

    if (!stringp(chunk) || chunk == "")
      break;

    chunks += ({ chunk });
    line += line_count;
  }

  if (!sizeof(chunks)) {
    while (offset < size) {
      read_size = chunk_size;

      if (offset + read_size > size)
        read_size = size - offset;

      read_error = catch(chunk = read_bytes(file, offset, read_size));

      if (read_error) {
        if (chunk_size <= 64) {
          last_load_error = "read_bytes failed for " + file + ": " + read_error;

          break;
        }

        chunk_size = chunk_size / 2;

        if (chunk_size < 64)
          chunk_size = 64;

        continue;
      }

      if (!stringp(chunk) || chunk == "")
        break;

      chunks += ({ chunk });
      offset += strlen(chunk);
    }
  }

  if (!sizeof(chunks))
    return 0;

  contents = implode(chunks, "");

  if (!stringp(contents) || contents == "")
    return 0;

  return contents;
}

void create() {
  string map_json;
  mixed load_error;

  map_json = "/chapter/prologue/area/wilderness/wilderness_nw.json";
  last_load_error = 0;

  /* Preloaded at startup so player movement never parses JSON. */
  load_error = catch(reload_wilderness(map_json));

  if (load_error) {
    last_load_error = "" + load_error;
    rooms_by_id = ([]);
    terrain_by_code = ([]);
    loaded = 1;
    room_count = 0;
    rooms_array_count = 0;
    terrain_code_count = 0;
  }

  log_preload_status(load_error);

  return;
}

void reload_wilderness(string map_json) {
  rooms_by_id = ([]);
  terrain_by_code = ([]);
  loaded = 0;
  room_count = 0;
  map_json_size = 0;
  terrain_json_size = 0;
  rooms_array_count = 0;
  terrain_code_count = 0;
  last_load_error = 0;

  load_wilderness(map_json);

  return;
}

void load_wilderness(string map_json) {
  mixed data, terrain_data, rooms;
  mixed load_error;
  mapping terrain, room_data;
  mapping room;
  string contents, terrain_contents, room_id, terrain_json;
  string *map_json_files;
  string map_file;
  int size, i, file_rooms_count;

  if (!mapp(rooms_by_id))
    rooms_by_id = ([]);

  if (loaded) return;

  if (!stringp(map_json)) {
    loaded = 1;

    return;
  }

  map_json_files = ({
    "/chapter/prologue/area/wilderness/wilderness_nw.json",
    "/chapter/prologue/area/wilderness/wilderness_sw.json",
    "/chapter/prologue/area/wilderness/wilderness_ne.json",
    "/chapter/prologue/area/wilderness/wilderness_se.json"
  });
  map_json_size = 0;
  rooms_array_count = 0;

  terrain_json = "/chapter/prologue/area/wilderness/wilderness_terrain.json";
  terrain_json_size = file_size(terrain_json);
  terrain_contents = read_wilderness_file(terrain_json);

  if (stringp(terrain_contents) && terrain_contents != "") {
    load_error = catch(terrain_data = parse_json(terrain_contents));

    if (!load_error && mapp(terrain_data))
      terrain = terrain_data;
    else if (load_error)
      last_load_error = "wilderness_terrain.json parse failed: " + load_error;
  }

  if (mapp(terrain)) {
    terrain_by_code = terrain;
    terrain_code_count = sizeof(keys(terrain_by_code));
  }
  if (!mapp(terrain_by_code))
    terrain_by_code = ([]);

  i = 0;

  while (i < sizeof(map_json_files)) {
    map_file = map_json_files[i];
    size = file_size(map_file);
    map_json_size += size;

    if (size <= 0) {
      last_load_error = map_file + " missing or empty.";
      loaded = 1;

      return;
    }

    contents = read_wilderness_file(map_file);

    if (!stringp(contents) || contents == "") {
      last_load_error = map_file + " could not be read.";
      loaded = 1;

      return;
    }

    load_error = catch(data = parse_json(contents));

    if (load_error) {
      last_load_error = map_file + " parse failed: " + load_error;
      loaded = 1;

      return;
    }

    if (!mapp(data)) {
      last_load_error = map_file + " parse returned non-mapping.";
      loaded = 1;

      return;
    }

    rooms = data["rooms"];

    if (!pointerp(rooms)) {
      last_load_error = map_file + " rooms missing or non-array.";
      loaded = 1;

      return;
    }

    file_rooms_count = sizeof(rooms);
    rooms_array_count += file_rooms_count;

    /* Normalize room data for O(1) lookup and future overlay layers. */
    room_id = 0;
    room_data = 0;
    room = 0;
    file_rooms_count = 0;
    file_rooms_count = sizeof(rooms);

    while (file_rooms_count > 0) {
      file_rooms_count -= 1;
      room_data = rooms[file_rooms_count];

      if (mapp(room_data)) {
        room_id = room_data["id"];

        if (stringp(room_id)) {
          rooms_by_id[room_id] = room_data;
        }
      }
    }

    i += 1;
  }

  room_count = sizeof(keys(rooms_by_id));

  loaded = 1;

  return;
}

mapping debug_status() {
  return ([
    "loaded" : loaded,
    "room_count" : room_count,
    "map_json_size" : map_json_size,
    "terrain_json_size" : terrain_json_size,
    "rooms_array_count" : rooms_array_count,
    "terrain_code_count" : terrain_code_count,
    "last_load_error" : last_load_error
  ]);
}

mapping room(string room_id) {
  mapping room_data;

  if (!room_id) return 0;

  if (!mapp(rooms_by_id)) {
    rooms_by_id = ([]);
    loaded = 0;
  }

  room_data = rooms_by_id[room_id];

  if (!mapp(room_data)) return 0;

  return room_data;
}

mapping exits(string room_id) {
  mapping room_data, exits;

  room_data = room(room_id);

  if (!room_data) return ([]);

  exits = room_data["exits"];

  if (!mapp(exits)) return ([]);

  return exits;
}

string terrain(string room_id) {
  mapping room_data;
  string terrain_code;

  room_data = room(room_id);

  if (!room_data) return 0;

  terrain_code = room_data["terrain"];

  if (!stringp(terrain_code)) return 0;

  return terrain_code;
}

mapping terrain_info(string terrain_code) {
  mapping terrain;

  if (!stringp(terrain_code)) return 0;

  if (!mapp(terrain_by_code)) return 0;

  terrain = terrain_by_code[terrain_code];

  if (!mapp(terrain)) return 0;

  return terrain;
}

int room_exists(string room_id) {
  if (!stringp(room_id)) return 0;

  if (mapp(rooms_by_id[room_id])) return 1;

  return 0;
}
