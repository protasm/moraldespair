inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sagging Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1550",
    "west" : "/chapter/prologue/area/dead/room1548",
  ]);

  set_light(1);
}
