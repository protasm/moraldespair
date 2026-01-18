#define WILDERNESS_D "/daemon/wilderness_d"

inherit "room/room";

/*
 * Virtual wilderness room. It stores only a room id and queries the daemon
 * for all state, keeping room data centralized and easy to extend.
 */
string room_id;
string terrain;

void set_room_id(string id);
string query_room_id();
string query_terrain();
void set_exits();
void set_descriptions();
int sort_dirs(string a, string b);
int move(string str);
int move_alias(string str);
int move_direction(string direction);

void reset(int arg) {
  if (arg) return;

  set_light(1);

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

  if (!mappingp(terrain_info)) {
    terrain_info = WILDERNESS_D->query_terrain_info("default");
  }

  if (mappingp(terrain_info)) {
    short_name = terrain_info["short"];
    long_name = terrain_info["long"];
  }

  if (stringp(short_name)) {
    short_desc = short_name;
  } else {
    short_desc = "Wilderness";
  }

  if (stringp(long_name)) {
    long_desc = long_name;
  } else {
    long_desc = "The land here is quiet and open. No clear paths remain.";
  }

  return;
}

void init() {
  if (!room_id) return;

  set_exits();

  ::init();

  return;
}

void set_exits() {
  mapping exits;
  string *dirs;
  string destination, resolved;
  int i;

  exits = WILDERNESS_D->query_exits(room_id);
  dirs = m_indices(exits);

  if (!pointerp(dirs)) {
    dest_dir = ({});

    return;
  }

  dirs = sort_array(dirs, #'sort_dirs);
  dest_dir = ({});

  i = 0;

  while (i < sizeof(dirs)) {
    destination = exits[dirs[i]];

    if (stringp(destination)) {
      if (WILDERNESS_D->room_exists(destination))
        resolved = "room/wilderness_room#" + destination;
      else
        resolved = destination;

      dest_dir += ({ resolved, dirs[i] });
    }

    i += 1;
  }

  return;
}

int move(string str) {
  string direction;

  direction = query_verb();

  return move_direction(direction);
}

int move_alias(string str) {
  string canonical;

  if (!exit_aliases) return 0;

  canonical = exit_aliases[query_verb()];

  if (!canonical) return 0;

  return move_direction(canonical);
}

int move_direction(string direction) {
  int i;
  string destination, target_id, target_terrain;

  i = 1;

  while (i < sizeof(dest_dir)) {
    if (direction == dest_dir[i]) {
      destination = dest_dir[i - 1];

      if (terrain != "w") {
        if (sscanf(destination, "room/wilderness_room#%s", target_id) == 1) {
          target_terrain = WILDERNESS_D->query_terrain(target_id);

          if (target_terrain == "w") {
            write("There is a body of water there.\n");

            return 1;
          }
        }
      }

      this_player()->move_player(dest_dir[i] + "#" + dest_dir[i - 1]);

      return 1;
    }

    i += 2;
  }

  return 1;
}

int sort_dirs(string a, string b) {
  if (a == b) return 0;

  if (strstr(a, b) == 0) return 1;

  if (strstr(b, a) == 0) return -1;

  if (a < b) return -1;

  return 1;
}
