inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Windmill Base";
  long_desc = "The base of a windmill stands open to the wind, its beams creaking. Grain dust\nhas long settled into the floor.\n";
  dest_dir = ([
    "up":"/chapter/prologue/area/silent/room929",
    "west":"/chapter/prologue/area/silent/room927",
    "east":"/chapter/prologue/area/silent/room928",
    "south":"/chapter/prologue/area/silent/room319",
  ]);

  set_light(1);
}
