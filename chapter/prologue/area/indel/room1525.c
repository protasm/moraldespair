inherit "room/room";

void create() {
  ::create();

  short_desc = "Hollow Split Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1524",
    "south" : "/chapter/prologue/area/indel/room1526",
    "east" : "/chapter/prologue/area/indel/room1606",
  ]);

  set_light(1);
}

void init() {
  ::init();

  //add_action("block_exit", "east");
}

int block_exit() {
  write("The way is blocked by a choke of fallen stone.\n");

  return 1;
}
