inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1538", "east",
    "chapter/prologue/area/indel/room1536", "west",
  });

  set_light(1);
}
