inherit "/room/room";

void create() {
  ::create();

  short_desc = "Splintered Sunk Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1552",
    "west" : "/chapter/prologue/area/dead/room1550",
  ]);

  set_light(1);
}
