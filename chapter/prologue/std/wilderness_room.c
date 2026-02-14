#define WILDERNESS_D "/daemon/wilderness_d"

inherit "/chapter/prologue/std/room";

/*
 * Virtual wilderness room. It stores only a room id and queries the daemon
 * for all state, keeping room data centralized and easy to extend.
 */
string wilderness_room_id, terrain_code;
void set_descriptions();
void set_exits();

void create() {
  ::create();

  if (wilderness_room_id) set_descriptions();
}

void set_room_id(string id) {
  object cache;

  wilderness_room_id = id;

  set_descriptions();
  cache = link_cache();

  if (objectp(cache) && function_exists("init_for_room", cache))
    cache->init_for_room(this_object());

  return;
}

string room_id() {
  return wilderness_room_id;
}

string terrain() {
  return terrain_code;
}

string link_endpoint_id() {
  string endpoint_id;

  endpoint_id = "";

  if (stringp(wilderness_room_id) && wilderness_room_id != "")
    endpoint_id = "/chapter/prologue/std/wilderness_room#" + wilderness_room_id;
  else
    endpoint_id = base_name(this_object());

  return endpoint_id;
}

void set_descriptions() {
  object wilderness_daemon;
  mapping terrain_info;
  string short_name, long_name, terrain_from_daemon;

  if (!wilderness_room_id) return;

  terrain_code = "default";
  terrain_info = 0;
  short_name = 0;
  long_name = 0;
  terrain_from_daemon = 0;
  wilderness_daemon = find_object(WILDERNESS_D);

  if (!objectp(wilderness_daemon))
    wilderness_daemon = load_object(WILDERNESS_D);

  /*
   * Descriptions should never fail room creation. If wilderness_d is not
   * available, this room still resolves with default prose.
   */
  if (objectp(wilderness_daemon)) {
    terrain_from_daemon = wilderness_daemon->terrain(wilderness_room_id);

    if (stringp(terrain_from_daemon) && terrain_from_daemon != "")
      terrain_code = terrain_from_daemon;

    terrain_info = wilderness_daemon->terrain_info(terrain_code);

    if (!mapp(terrain_info))
      terrain_info = wilderness_daemon->terrain_info("default");
  }

  if (mapp(terrain_info)) {
    short_name = terrain_info["short"];
    long_name = terrain_info["long"];
  }

  if (stringp(short_name))
    short_desc = short_name;
  else
    short_desc = "Wilderness";

  if (stringp(long_name))
    long_desc = long_name;
  else
    long_desc = "The land here is quiet and open. No clear paths remain.";

  return;
}

void set_exits() {
  /*
   * Exits for prologue rooms are resolved via LINK_D + MOVE_D.
   * Wilderness exits remain daemon-backed data and do not write legacy
   * dest_dir mappings in this room implementation.
   */
  return;
}
