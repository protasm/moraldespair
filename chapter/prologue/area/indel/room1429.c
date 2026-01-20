inherit "room/room";

void create() {
  ::create();

  short_desc = "Spalled Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1428", "north",
    "chapter/prologue/area/indel/room1430", "south",
  });

  set_light(1);
}
