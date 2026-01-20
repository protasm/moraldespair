inherit "room/room";

void create() {
  ::create();

  short_desc = "Jagged Split Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Chunks of wall have been scooped away, leaving raw ribs of stone. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1543", "north",
    "domain/original/area/indel/room1547", "east",
    "domain/original/area/indel/room1545", "west",
  });

  set_light(1);
}
