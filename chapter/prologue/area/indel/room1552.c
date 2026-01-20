inherit "room/room";

void create() {
  ::create();

  short_desc = "Shattered Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1553", "east",
    "chapter/prologue/area/indel/room1551", "west",
  });

  set_light(1);
}
