inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Post";
  long_desc = "A low guard post slumps beside the road, its roof fallen in. The doorway is\nfilled with debris.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room341", "south",
    "domain/original/area/exedoria/room350", "north",
  });
}
