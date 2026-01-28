inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1522",
    "south" : "/chapter/prologue/area/dead/room1524",
  ]);

  set_light(1);
}
