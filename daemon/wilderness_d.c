#include "/daemon/wilderness_d.h"

/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
mapping rooms_by_id;
mapping terrain_by_code;
int loaded, room_count;

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
  int line, line_count;

  if (!stringp(file)) {
    return 0;
  }

  chunks = ({ });
  line = 1;
  line_count = 500;

  while (1) {
    chunk = read_file(file, line, line_count);

    if (!chunk) {
      break;
    }

    chunks += ({ chunk });
    line += line_count;
  }

  if (!sizeof(chunks)) {
    return 0;
  }

  contents = implode(chunks, "");

  if (!stringp(contents) || contents == "") {
    return 0;
  }

  return contents;
}

void create() {
  string map_json;
  mixed load_error;

  map_json = "/chapter/prologue/wilderness.json";

  /* Preloaded at startup so player movement never parses JSON. */
  load_error = catch(reload_wilderness(map_json));

  if (load_error) {
    rooms_by_id = ([]);
    terrain_by_code = ([]);
    loaded = 1;
    room_count = 0;
  }

  return;
}

void reload_wilderness(string map_json) {
  rooms_by_id = ([]);
  terrain_by_code = ([]);
  loaded = 0;
  room_count = 0;

  load_wilderness(map_json);

  return;
}

void load_wilderness(string map_json) {
  mixed data, rooms;
  mapping terrain;
  mapping room;
  string contents, room_id;
  int size, i;

  if (!mapp(rooms_by_id))
    rooms_by_id = ([]);

  if (loaded) return;

  if (!stringp(map_json)) {
    loaded = 1;

    return;
  }

  size = file_size(map_json);

  if (size <= 0) {
    loaded = 1;

    return;
  }

  contents = read_wilderness_file(map_json);

  if (!contents) {
    loaded = 1;

    return;
  }

  data = parse_json(contents);

  if (!mapp(data)) {
    loaded = 1;

    return;
  }

  terrain = data["terrain"];

  if (mapp(terrain)) {
    terrain_by_code = terrain;
  }

  rooms = data["rooms"];

  if (!pointerp(rooms)) {
    loaded = 1;

    return;
  }

  /* Normalize room data for O(1) lookup and future overlay layers. */
  i = 0;

  while (i < sizeof(rooms)) {
    room = rooms[i];

    if (mapp(room)) {
      room_id = room["id"];

      if (stringp(room_id)) {
        rooms_by_id[room_id] = room;
        room_count += 1;
      }
    }

    i += 1;
  }

  loaded = 1;

  return;
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
