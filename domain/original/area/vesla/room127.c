inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old City Gate";
  long_desc = "A battered gateway stands between worn walls, its lintel cracked and sagging.\n"
              + "Dust gathers in the deep grooves of the threshold, and no sound follows the\n"
              + "road beyond.\n";
  dest_dir = ({
    "domain/original/area/vesla/room128", "west",
    "domain/original/area/vesla/room126", "east",
    "domain/original/area/vesla/room878", "north",
  });
}
