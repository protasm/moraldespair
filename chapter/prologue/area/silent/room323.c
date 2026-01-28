inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Row End";
  long_desc = "The line of grand facades fades into a broken cul-de-sac. A fallen wall spills\ninto the street, blocking the far end.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room317",
    "north":"/chapter/prologue/area/silent/room324",
  ]);

  set_light(1);
}
