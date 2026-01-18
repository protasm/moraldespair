#include "/daemon/wilderness_d.h"

/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
string map_file;
mapping rooms_by_id;
int loaded;
int debug_enabled;
int room_count;

void create() {
  map_file = "/domain/original/wilderness.json";
  rooms_by_id = ([]);
  loaded = 0;
  debug_enabled = 1;
  room_count = 0;

  /* Preloaded at startup so player movement never parses JSON. */
  load_wilderness();

  return;
}

void set_debug(int enabled) {
  if (enabled) {
    debug_enabled = 1;
  } else {
    debug_enabled = 0;
  }

  debug_log("debug set to " + debug_enabled);

  return;
}

int query_debug() {
  return debug_enabled;
}

void debug_log(string message) {
  string entry;

  if (!debug_enabled) {
    return;
  }

  if (!stringp(message)) {
    return;
  }

  entry = ctime(time()) + " " + message + "\n";
  log_file("wilderness", entry);

  return;
}

mapping query_stats() {
  mapping stats;

  stats = ([]);
  stats["map_file"] = map_file;
  stats["loaded"] = loaded;
  stats["rooms"] = room_count;
  stats["debug"] = debug_enabled;

  return stats;
}

void load_wilderness() {
  mixed data;
  mixed rooms;
  mapping room;
  string contents;
  string room_id;
  int size;
  int i;

  if (!mappingp(rooms_by_id)) {
    rooms_by_id = ([]);
  }

  if (loaded) {
    return;
  }

  if (!stringp(map_file)) {
    map_file = "/domain/original/wilderness.json";
  }

  size = file_size(map_file);
  if (size <= 0) {
    debug_log("map file missing or empty: " + map_file);
    loaded = 1;
    return;
  }

  contents = read_file(map_file);
  if (!contents) {
    debug_log("map file unreadable: " + map_file);
    loaded = 1;
    return;
  }

  data = json_parse(contents);
  if (!mappingp(data)) {
    debug_log("map file parse failed: " + map_file);
    loaded = 1;
    return;
  }

  rooms = data["rooms"];
  if (!pointerp(rooms)) {
    debug_log("map file missing rooms array: " + map_file);
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

  debug_log("loaded wilderness rooms: " + room_count);
  loaded = 1;
  return;
}

void reload_wilderness() {
  rooms_by_id = ([]);
  loaded = 0;
  room_count = 0;

  debug_log("reload requested");
  load_wilderness();

  return;
}

mapping query_room(string room_id) {
  mapping room;

  if (!room_id) {
    return 0;
  }

  if (!mappingp(rooms_by_id)) {
    rooms_by_id = ([]);
    loaded = 0;
  }

  if (!loaded) {
    load_wilderness();
  }

  room = rooms_by_id[room_id];
  if (!mappingp(room)) {
    debug_log("room id not found: " + room_id);
    return 0;
  }

  return room;
}

mapping query_exits(string room_id) {
  mapping room;
  mapping exits;

  room = query_room(room_id);
  if (!room) {
    return ([]);
  }

  exits = room["exits"];
  if (!mappingp(exits)) {
    return ([]);
  }

  return exits;
}

string query_terrain(string room_id) {
  mapping room;
  string terrain;

  room = query_room(room_id);
  if (!room) {
    return 0;
  }

  terrain = room["terrain"];
  if (!stringp(terrain)) {
    return 0;
  }

  return terrain;
}

int room_exists(string room_id) {
  if (!stringp(room_id)) {
    return 0;
  }

  if (mappingp(rooms_by_id[room_id])) {
    return 1;
  }

  return 0;
}
