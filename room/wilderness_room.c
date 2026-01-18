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
  if (!room_id) return;

  terrain = WILDERNESS_D->query_terrain(room_id);

  switch (terrain) {
    case "p":
      short_desc = "Open Plain";
      long_desc = "A flat plain stretches out in every direction. Wind presses through short grass.";
      break;
    case "f":
      short_desc = "Thin Forest";
      long_desc = "Sparse trees stand in uneven clusters. The ground is shaded and quiet.";
      break;
    case "h":
      short_desc = "Low Hills";
      long_desc = "Low hills roll in soft, broken lines. Stone shows through thin soil.";
      break;
    default:
      short_desc = "Wilderness";
      long_desc = "The land here is quiet and open. No clear paths remain.";
      break;
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

int sort_dirs(string a, string b) {
  if (a == b) return 0;

  if (strstr(a, b) == 0) return 1;

  if (strstr(b, a) == 0) return -1;

  if (a < b) return -1;

  return 1;
}
