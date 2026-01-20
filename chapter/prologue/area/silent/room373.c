inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Hill Path";
  long_desc = "The path climbs a low rise where the ground is bare and windy. A line of trees\nleans over the slope.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room371", "south",
    "chapter/prologue/area/silent/room374", "north",
  });
}
