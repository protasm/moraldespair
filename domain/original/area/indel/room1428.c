inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Bleached Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1427", "north",
    "domain/original/area/indel/room1429", "south",
  });

  set_light(1);
}
