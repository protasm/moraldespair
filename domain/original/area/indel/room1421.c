inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1420", "north",
    "domain/original/area/indel/room1422", "south",
  });

  set_light(1);
}
