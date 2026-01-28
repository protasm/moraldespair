inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Small Den";
  long_desc = "A low room sits tucked under a stair, its walls scratched and scuffed. A toy\nchest lies smashed in a corner.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room909",
  ]);

  set_light(1);
}
