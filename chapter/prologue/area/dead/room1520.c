inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1516",
    "south" : "/chapter/prologue/area/dead/room1521",
  ]);

  set_light(1);
}
