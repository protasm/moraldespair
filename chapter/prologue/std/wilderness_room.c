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
  mapping terrain_info, room_data, daemon_status;
  string short_name, long_name, terrain_from_daemon, raw_room_terrain;
  string debug_text, terrain_lookup_code, daemon_load_error;
  int daemon_ready, has_room, has_terrain_info, used_default_fallback;
  int daemon_loaded, daemon_room_count, daemon_map_size;
  int daemon_terrain_size, daemon_rooms_array_count, daemon_terrain_code_count;

  if (!wilderness_room_id) return;

  terrain_code = "default";
  terrain_info = 0;
  room_data = 0;
  short_name = 0;
  long_name = 0;
  terrain_from_daemon = 0;
  raw_room_terrain = 0;
  debug_text = "";
  terrain_lookup_code = "default";
  daemon_load_error = 0;
  daemon_ready = 0;
  has_room = 0;
  has_terrain_info = 0;
  used_default_fallback = 0;
  daemon_loaded = 0;
  daemon_room_count = 0;
  daemon_map_size = 0;
  daemon_terrain_size = 0;
  daemon_rooms_array_count = 0;
  daemon_terrain_code_count = 0;
  wilderness_daemon = find_object(WILDERNESS_D);

  if (!objectp(wilderness_daemon))
    wilderness_daemon = load_object(WILDERNESS_D);

  /*
   * Descriptions should never fail room creation. If wilderness_d is not
   * available, this room still resolves with default prose.
   */
  if (objectp(wilderness_daemon)) {
    daemon_ready = 1;
    daemon_status = wilderness_daemon->debug_status();

    if (mapp(daemon_status)) {
      daemon_loaded = daemon_status["loaded"];
      daemon_room_count = daemon_status["room_count"];
      daemon_map_size = daemon_status["map_json_size"];
      daemon_terrain_size = daemon_status["terrain_json_size"];
      daemon_rooms_array_count = daemon_status["rooms_array_count"];
      daemon_terrain_code_count = daemon_status["terrain_code_count"];
      daemon_load_error = daemon_status["last_load_error"];
    }

    has_room = wilderness_daemon->room_exists(wilderness_room_id);
    room_data = wilderness_daemon->room(wilderness_room_id);

    if (mapp(room_data))
      raw_room_terrain = room_data["terrain"];

    terrain_from_daemon = wilderness_daemon->terrain(wilderness_room_id);

    if (stringp(terrain_from_daemon) && terrain_from_daemon != "")
      terrain_code = terrain_from_daemon;

    terrain_lookup_code = terrain_code;
    terrain_info = wilderness_daemon->terrain_info(terrain_code);
    has_terrain_info = mapp(terrain_info);

    if (!mapp(terrain_info)) {
      used_default_fallback = 1;
      terrain_lookup_code = "default";
      terrain_info = wilderness_daemon->terrain_info("default");
    }
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

  debug_text += "\n[WDBG] room_id=" + wilderness_room_id;
  debug_text += " daemon_ready=" + daemon_ready;
  debug_text += " room_exists=" + has_room;
  debug_text += "\n[WDBG] raw_room_terrain=" + raw_room_terrain;
  debug_text += " terrain_from_daemon=" + terrain_from_daemon;
  debug_text += " terrain_code=" + terrain_code;
  debug_text += " lookup_code=" + terrain_lookup_code;
  debug_text += "\n[WDBG] terrain_info_found=" + has_terrain_info;
  debug_text += " default_fallback=" + used_default_fallback;
  debug_text += " short_desc=" + short_desc;
  debug_text += "\n[WDBG] daemon_loaded=" + daemon_loaded;
  debug_text += " daemon_room_count=" + daemon_room_count;
  debug_text += " map_size=" + daemon_map_size;
  debug_text += " terrain_size=" + daemon_terrain_size;
  debug_text += "\n[WDBG] rooms_array_count=" + daemon_rooms_array_count;
  debug_text += " terrain_code_count=" + daemon_terrain_code_count;
  debug_text += "\n[WDBG] last_load_error=" + daemon_load_error;

  long_desc += debug_text;

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
