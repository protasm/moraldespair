inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Watch";
  long_desc = "A squat tower rises above the wall, its stairs broken. The top is open to rain\nand birds.\n";
  dest_dir = ([
    "down":"/chapter/prologue/area/silent/room920",
    "north":"/chapter/prologue/area/silent/room922",
  ]);

  set_light(1);
}
