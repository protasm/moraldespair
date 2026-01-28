inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "A long stretch of road lies quiet under a thin scatter of leaves. The gutters\nare choked with soil and moss.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room306",
    "east":"/chapter/prologue/area/silent/room304",
    "north":"/chapter/prologue/area/silent/room393",
  ]);

  set_light(1);
}
