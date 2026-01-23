inherit "room/room";

void create() {
  ::create();

  short_desc = "Blasted Sunk Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/indel/room1549",
    "west" : "/chapter/prologue/area/indel/room1547",
  ]);

  set_light(1);
}
