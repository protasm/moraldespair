inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1528",
    "south" : "/chapter/prologue/area/dead/room1530",
  ]);

  set_light(1);
}
