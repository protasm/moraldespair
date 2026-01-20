inherit "room/room";

void create() {
  ::create();

  short_desc = "Library Door";
  long_desc = "An arched entry stands flanked by shattered shelves. Damp paper lies in curled\nfragments on the stone.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room357", "south",
    "chapter/prologue/area/silent/room361", "west",
    "chapter/prologue/area/silent/room355", "east",
    "chapter/prologue/area/silent/room362", "north",
  });

  set_light(1);
}
