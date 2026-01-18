#define WILDERNESS_D "/daemon/wilderness_d"

/*
 * Virtual wilderness room. It stores only a room id and queries the daemon
 * for all state, keeping room data centralized and easy to extend.
 */
string room_id;

void set_room_id(string id);

void create() {
  string name;
  string id;

  name = object_name(this_object());

  if (sscanf(name, "room/wilderness_room#%s", id) == 1) {
    set_room_id(id);
  }

  return;
}

void set_room_id(string id) {
  room_id = id;

  return;
}

string query_room_id() {
  return room_id;
}

void init() {
  mapping exits;
  string *dirs;
  int i;

  if (!room_id) {
    return;
  }

  exits = WILDERNESS_D->query_exits(room_id);
  dirs = m_indices(exits);

  i = 0;
  while (i < sizeof(dirs)) {
    add_action("move", dirs[i]);
    i += 1;
  }

  return;
}

int move(string arg) {
  mapping exits;
  string destination;

  if (!room_id) {
    return 0;
  }

  exits = WILDERNESS_D->query_exits(room_id);
  destination = exits[query_verb()];
  if (!stringp(destination)) {
    return 0;
  }

  this_player()->move_player(query_verb() + "#room/wilderness_room#" + destination);

  return 1;
}

string short() {
  string terrain;

  terrain = WILDERNESS_D->query_terrain(room_id);

  if (terrain == "p") {
    return "Open Plain";
  }

  if (terrain == "f") {
    return "Thin Forest";
  }

  if (terrain == "h") {
    return "Low Hills";
  }

  return "Wilderness";
}

string long() {
  string terrain;

  terrain = WILDERNESS_D->query_terrain(room_id);

  if (terrain == "p") {
    return "A flat plain stretches out in every direction. "
      + "Wind presses through short grass.";
  }

  if (terrain == "f") {
    return "Sparse trees stand in uneven clusters. "
      + "The ground is shaded and quiet.";
  }

  if (terrain == "h") {
    return "Low hills roll in soft, broken lines. "
      + "Stone shows through thin soil.";
  }

  return "The land here is quiet and open. "
    + "No clear path remains.";
}

mapping query_exits() {
  if (!room_id) {
    return ([]);
  }

  return WILDERNESS_D->query_exits(room_id);
}
