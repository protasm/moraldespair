inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shadow Bend";
  long_desc = "A tight bend hides the alley from the street, keeping it dark and stale. The\nwalls are pocked with old nail holes and cracks.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room325", "east",
    "domain/original/area/exedoria/room327", "north",
  });
}
