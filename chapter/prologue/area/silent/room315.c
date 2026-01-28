inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silent Row";
  long_desc = "A formal row of buildings rises in matched stone. Windows stare out as dark,\nbroken squares.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room320",
    "west":"/chapter/prologue/area/silent/room314",
    "east":"/chapter/prologue/area/silent/room316",
    "north":"/chapter/prologue/area/silent/room321",
  ]);

  set_light(1);
}
