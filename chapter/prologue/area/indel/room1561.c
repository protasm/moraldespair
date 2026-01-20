inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1562", "north",
    "chapter/prologue/area/indel/room1560", "south",
  });

  set_light(1);
}
