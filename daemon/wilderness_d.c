#include "/daemon/wilderness_d.h"

/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
mapping rooms_by_id;
mapping terrain_by_code;
int loaded, room_count;

string read_wilderness_file(string file) {
  string contents, chunk;
  int line, line_count;

  if (!stringp(file)) {
    return 0;
  }

  contents = "";
  line = 1;
  line_count = 500;

  while (1) {
    chunk = read_file(file, line, line_count);

    if (!chunk) {
      break;
    }

    contents += chunk;
    line += line_count;
  }

  if (contents == "") {
    return 0;
  }

  return contents;
}

void create() {
  string map_json;

  map_json = "/chapter/prologue/wilderness.json";

  /* Preloaded at startup so player movement never parses JSON. */
  reload_wilderness(map_json);

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

  if (!mappingp(rooms_by_id))
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

  data = json_parse(contents);

  if (!mappingp(data)) {
    loaded = 1;

    return;
  }

  terrain = data["terrain"];

  if (mappingp(terrain)) {
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

    if (mappingp(room)) {
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

mapping query_room(string room_id) {
  mapping room;

  if (!room_id) return 0;

  if (!mappingp(rooms_by_id)) {
    rooms_by_id = ([]);
    loaded = 0;
  }

  room = rooms_by_id[room_id];

  if (!mappingp(room)) return 0;

  return room;
}

mapping query_exits(string room_id) {
  mapping room, exits;

  room = query_room(room_id);

  if (!room) return ([]);

  exits = room["exits"];

  if (!mappingp(exits)) return ([]);

  return exits;
}

string query_terrain(string room_id) {
  mapping room;
  string terrain;

  room = query_room(room_id);

  if (!room) return 0;

  terrain = room["terrain"];

  if (!stringp(terrain)) return 0;

  return terrain;
}

mapping query_terrain_info(string terrain_code) {
  mapping terrain;

  if (!stringp(terrain_code)) return 0;

  if (!mappingp(terrain_by_code)) return 0;

  terrain = terrain_by_code[terrain_code];

  if (!mappingp(terrain)) return 0;

  return terrain;
}

int room_exists(string room_id) {
  if (!stringp(room_id)) return 0;

  if (mappingp(rooms_by_id[room_id])) return 1;

  return 0;
}
