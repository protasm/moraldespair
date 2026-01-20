inherit "room/room";

void create() {
  ::create();

  short_desc = "Split Bleached Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Fragments of arches and lintels hang at odd angles, cut and burned through. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1430", "north",
    "domain/original/area/indel/room1432", "south",
  });

  set_light(1);
}
