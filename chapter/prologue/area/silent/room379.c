inherit "room/room";

void create() {
  ::create();

  short_desc = "Gravel Rise";
  long_desc = "The gravel path climbs a slope scattered with loose stone. It narrows where\nthe hill has begun to slip.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room380", "east",
    "chapter/prologue/area/silent/room378", "west",
  });

  set_light(1);
}
