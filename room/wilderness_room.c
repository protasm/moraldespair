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
    case "lf":
      short_desc = "Light Forest";
      long_desc = "Thin trunks rise with wide gaps between them. Dull light falls"
        + " across dry needles and scattered brush.";
      break;
    case "p":
      short_desc = "Open Plain";
      long_desc = "A flat plain stretches out in every direction. Wind presses"
        + " through short grass.";
      break;
    case "f":
      short_desc = "Forest";
      long_desc = "Trees gather close, their limbs tangled above the ground."
        + " The understory is thin and uneven.";
      break;
    case "df":
      short_desc = "Deep Forest";
      long_desc = "Dense growth closes in on all sides. The canopy blocks most"
        + " of the light.";
      break;
    case "w":
      short_desc = "Open Water";
      long_desc = "Dark water spreads without clear edge. Low ripples drift"
        + " across the surface.";
      break;
    case "d":
      short_desc = "Desert";
      long_desc = "Pale sand runs out in hard waves. The air hangs dry and still.";
      break;
    case "h":
      short_desc = "Low Hills";
      long_desc = "Low hills roll in soft, broken lines. Stone shows through"
        + " thin soil.";
      break;
    case "m":
      short_desc = "Marsh";
      long_desc = "Wet ground shifts beneath a cover of reeds. Shallow pools"
        + " gleam between mud and grass.";
      break;
    case "s":
      short_desc = "Swamp";
      long_desc = "Dark water sits between heavy growth. Rotting trunks lean"
        + " over the still surface.";
      break;
    case "b":
      short_desc = "Barrens";
      long_desc = "Bare earth stretches out with little sign of growth. Scattered"
        + " stones lie exposed to the wind.";
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
