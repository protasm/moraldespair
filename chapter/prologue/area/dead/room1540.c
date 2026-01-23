inherit "room/room";

void create() {
  ::create();

  short_desc = "Mossy Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Chunks of wall have been scooped away, leaving raw ribs of stone. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1541",
    "west" : "/chapter/prologue/area/dead/room1539",
  ]);

  set_light(1);
}
