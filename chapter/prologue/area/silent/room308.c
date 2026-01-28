inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Lane Start";
  long_desc = "A narrow lane begins between sagging houses. The stones are uneven and broken.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room309",
    "north":"/chapter/prologue/area/silent/room307",
  ]);

  set_light(1);
}
