inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "The path narrows where rubble has spilled from a broken stair. Dust and grit\nsoften the once-sharp edges.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room899", "south",
    "domain/original/area/exedoria/room897", "north",
  });
}
