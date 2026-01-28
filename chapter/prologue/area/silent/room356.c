inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Library Door";
  long_desc = "An arched entry stands flanked by shattered shelves. Damp paper lies in curled\nfragments on the stone.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room357",
    "west":"/chapter/prologue/area/silent/room361",
    "east":"/chapter/prologue/area/silent/room355",
    "north":"/chapter/prologue/area/silent/room362",
  ]);

  set_light(1);
}
