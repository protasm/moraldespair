inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Post";
  long_desc = "A low guard post slumps beside the road, its roof fallen in. The doorway is\nfilled with debris.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room341", "south",
    "chapter/prologue/area/silent/room350", "north",
  });

  set_light(1);
}
