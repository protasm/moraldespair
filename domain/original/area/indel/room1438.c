inherit "room/room";

void create() {
  ::create();

  short_desc = "Sundered Narrow Way";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1437", "north",
    "domain/original/area/indel/room1439", "south",
  });

  set_light(1);
}
