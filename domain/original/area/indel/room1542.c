inherit "room/room";

void create() {
  ::create();

  short_desc = "Scorched Sunk Split Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Chunks of wall have been scooped away, leaving raw ribs of stone. The path splits around a heap of fallen blocks, offering lines gone to ruin. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1534", "north",
    "domain/original/area/indel/room1591", "east",
    "domain/original/area/indel/room1541", "west",
  });

  set_light(1);
}
