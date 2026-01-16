inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "High Path";
  long_desc = "This path runs along a raised embankment of cracked stone. The drop to either\nside is softened by weeds.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room373", "south",
    "domain/original/area/exedoria/room375", "north",
  });
}
