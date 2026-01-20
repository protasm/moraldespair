inherit "room/room";

void create() {
  ::create();

  short_desc = "Slick Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1425", "north",
    "chapter/prologue/area/indel/room1427", "south",
  });

  set_light(1);
}
