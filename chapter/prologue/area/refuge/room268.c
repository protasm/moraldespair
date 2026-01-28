inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Barrack Road";
  long_desc =
    "Long stone halls march along the street, their roofs partly fallen. Rusted\n"
    "nails and timbers lie in heaps.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room267",
    "west" : "/chapter/prologue/area/refuge/room269",
  ]);

  set_light(1);
}
