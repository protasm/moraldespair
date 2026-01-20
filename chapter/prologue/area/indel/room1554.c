inherit "room/room";

void create() {
  ::create();

  short_desc = "Gritted Sunk Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1555", "east",
    "chapter/prologue/area/indel/room1553", "west",
  });

  set_light(1);
}
