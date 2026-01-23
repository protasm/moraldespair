inherit "room/room";

void create() {
  ::create();

  short_desc = "Sunk Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/indel/room1554",
    "west" : "/chapter/prologue/area/indel/room1552",
  ]);

  set_light(1);
}
