/*
 * Wilderness data is JSON-backed but normalized into a room-id mapping.
 * This keeps virtual room lookups fast and predictable as the map grows
 * while leaving room for future overlay layers keyed by the same ids.
 */
string map_file;
mapping rooms_by_id;
int loaded;

void create() {
  map_file = "/maps/moraldecay.json";
  rooms_by_id = ([]);
  loaded = 0;

  /* Preloaded at startup so player movement never parses JSON. */
  load_wilderness();

  return;
}

void load_wilderness() {
  mixed data;
  mixed rooms;
  mapping room;
  string contents;
  string room_id;
  int i;

  if (loaded) {
    return;
  }

  contents = read_file(map_file);
  if (!contents) {
    loaded = 1;
    return;
  }

  data = json_parse(contents);
  if (!mapp(data)) {
    loaded = 1;
    return;
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
      }
    }

    i += 1;
  }

  loaded = 1;
  return;
}

mapping query_room(string room_id) {
  mapping room;

  if (!room_id) {
    return 0;
  }

  room = rooms_by_id[room_id];
  if (!mapp(room)) {
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
  if (!mapp(exits)) {
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

  if (mapp(rooms_by_id[room_id])) {
    return 1;
  }

  return 0;
}
