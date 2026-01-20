inherit "room/room";

void create() {
  ::create();

  short_desc = "Seamed Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1559", "north",
    "chapter/prologue/area/indel/room1544", "south",
  });

  set_light(1);
}
