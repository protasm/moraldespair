#define WILDERNESS_D "/daemon/wilderness_d"

inherit "/chapter/prologue/std/room";

/*
 * Virtual wilderness room. It stores only a room id and queries the daemon
 * for all state, keeping room data centralized and easy to extend.
 */
string room_id, terrain;

void create() {
  ::create();

  if (room_id) set_descriptions();
}

void set_room_id(string id) {
  room_id = id;

  set_descriptions();

  return;
}

string query_room_id() {
  return room_id;
}

string query_terrain() {
  return terrain;
}

void set_descriptions() {
  mapping terrain_info;
  string short_name, long_name;

  if (!room_id) return;

  terrain = WILDERNESS_D->query_terrain(room_id);

  terrain_info = WILDERNESS_D->query_terrain_info(terrain);

  if (!mappingp(terrain_info))
    terrain_info = WILDERNESS_D->query_terrain_info("default");

  if (mappingp(terrain_info)) {
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
  mapping exits;
  string *dirs;
  string direction, destination, resolved;
  int i;

  exits = WILDERNESS_D->query_exits(room_id);
  dirs = m_indices(exits);

  if (!pointerp(dirs)) {
    dest_dir = ([]);

    return;
  }

  dirs = sort_array(dirs, #'sort_dirs);
  dest_dir = ([]);

  i = 0;

  while (i < sizeof(dirs)) {
    direction = dirs[i];
    destination = exits[direction];

    if (stringp(destination)) {
      if (WILDERNESS_D->room_exists(destination))
        resolved = "/chapter/prologue/std/wilderness_room#" + destination;
      else {
        if (destination[0] == '/')
          resolved = destination;
        else
          resolved = "/" + destination;
      }

      dest_dir[direction] = resolved;
    }

    i += 1;
  }

  return;
}

int sort_dirs(string a, string b) {
  if (a == b) return 0;

  if (strstr(a, b) == 0) return 1;

  if (strstr(b, a) == 0) return -1;

  if (a < b) return -1;

  return 1;
}
