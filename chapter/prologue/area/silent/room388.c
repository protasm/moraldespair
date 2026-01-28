inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Walk";
  long_desc = "A narrower walk skirts a line of study halls. The stones are uneven and\nspotted with moss.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room389",
    "west":"/chapter/prologue/area/silent/room387",
  ]);

  set_light(1);
}
