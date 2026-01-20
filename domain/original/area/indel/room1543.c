inherit "room/room";

void create() {
  ::create();

  short_desc = "Charred Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1544", "north",
    "domain/original/area/indel/room1546", "south",
  });

  set_light(1);
}
