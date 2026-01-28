inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Lichen Faded Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1519",
    "west" : "/chapter/prologue/area/dead/room1517",
  ]);

  set_light(1);
}
