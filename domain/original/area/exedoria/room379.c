inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gravel Rise";
  long_desc = "The gravel path climbs a slope scattered with loose stone. It narrows where\nthe hill has begun to slip.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room380", "east",
    "domain/original/area/exedoria/room378", "west",
  });
}
