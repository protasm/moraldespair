inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Library Door";
  long_desc = "An arched entry stands flanked by shattered shelves. Damp paper lies in curled\nfragments on the stone.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room357", "south",
    "domain/original/area/exedoria/room361", "west",
    "domain/original/area/exedoria/room355", "east",
    "domain/original/area/exedoria/room362", "north",
  });
}
