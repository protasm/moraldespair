inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "High Path";
  long_desc = "This path runs along a raised embankment of cracked stone. The drop to either\nside is softened by weeds.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room373", "south",
    "chapter/prologue/area/silent/room375", "north",
  });
}
