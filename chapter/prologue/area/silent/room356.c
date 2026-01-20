inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Library Door";
  long_desc = "An arched entry stands flanked by shattered shelves. Damp paper lies in curled\nfragments on the stone.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room357", "south",
    "chapter/prologue/area/silent/room361", "west",
    "chapter/prologue/area/silent/room355", "east",
    "chapter/prologue/area/silent/room362", "north",
  });
}
