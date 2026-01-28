inherit "/room/room";

void create() {
  ::create();

  short_desc = "Fractured Narrow Way";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1521",
    "south" : "/chapter/prologue/area/dead/room1523",
  ]);

  set_light(1);
}
