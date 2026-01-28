inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Hill Path";
  long_desc = "The path climbs a low rise where the ground is bare and windy. A line of trees\nleans over the slope.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room371",
    "north":"/chapter/prologue/area/silent/room374",
  ]);

  set_light(1);
}
