#include <debug_message.h>
#include "/daemon/wilderness_d.h"

/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
string map_json;
mapping rooms_by_id;
int loaded, room_count;

void reset(int arg) {
  if(arg) return;

  map_json = "/domain/original/wilderness.json";

  /* Preloaded at startup so player movement never parses JSON. */
  reload_wilderness();

  return;
}

void reload_wilderness() {
debug_message("Reloading wilderness...");
  rooms_by_id = ([]);
  loaded = 0;
  room_count = 0;

  load_wilderness();
debug_message("reloading wilderness complete\n.");

  return;
}

void load_wilderness() {
debug_message("Loading wilderness...");
  mixed data, rooms;
  mapping room;
  string contents, room_id;
  int size, i;

  if (!mappingp(rooms_by_id))
    rooms_by_id = ([]);

  if (loaded) {
debug_message("already loaded!\n");

    return;
  }

  if (!stringp(map_json)) {
    loaded = 1;

debug_message("!stringp(map_json)!\n");

    return;
  }

  size = file_size(map_json);

  if (size <= 0) {
    loaded = 1;

debug_message("size <= 0!\n");

    return;
  }

debug_message("reading: " + map_json);
  contents = read_file(map_json);

  if (!contents) {
    loaded = 1;

debug_message("!contents!\n");

    return;
  }

  data = json_parse(contents);

  if (!mappingp(data)) {
    loaded = 1;

debug_message("!mappingp(data)!\n");

    return;
  }

  rooms = data["rooms"];

  if (!pointerp(rooms)) {
    loaded = 1;

debug_message("!pointerp(rooms)!\n");

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

  debug_message("loading Wilderness complete.\n");
  debug_message("Loaded " + room_count + " rooms.\n");

  return;
}

mapping query_room(string room_id) {
  mapping room;

  if (!room_id) return 0;

  if (!mappingp(rooms_by_id)) {
    rooms_by_id = ([]);
    loaded = 0;
  }

  if (!loaded) load_wilderness();

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

int room_exists(string room_id) {
  if (!stringp(room_id)) return 0;

  if (mappingp(rooms_by_id[room_id])) return 1;

  return 0;
}
