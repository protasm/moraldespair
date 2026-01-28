inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Flagstone Path";
  long_desc = "Flat stones form a narrow path, each one tilted and cracked. Grass grows thick\nbetween the joints.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room916",
    "west":"/chapter/prologue/area/silent/room919",
    "east":"/chapter/prologue/area/silent/room918",
    "north":"/chapter/prologue/area/silent/room603",
  ]);

  set_light(1);
}
