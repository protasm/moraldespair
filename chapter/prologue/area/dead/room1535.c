inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1536",
    "west" : "/chapter/prologue/area/dead/room1557",
  ]);

  set_light(1);
}
