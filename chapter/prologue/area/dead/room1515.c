inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Eroded Faded Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1516",
    "west" : "/chapter/prologue/area/dead/room1514",
  ]);

  set_light(1);
}
