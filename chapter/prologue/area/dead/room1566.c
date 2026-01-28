inherit "/room/room";

void create() {
  ::create();

  short_desc = "Dusted Sunk Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Jagged ribs of stone show cuts and pitting, some edges glassed by heat. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1567",
    "south" : "/chapter/prologue/area/dead/room1565",
  ]);

  set_light(1);
}
