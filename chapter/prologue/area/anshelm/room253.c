inherit "room/room";

void create() {
  ::create();

  short_desc = "Dusty Way";
  long_desc =
    "Dust lies thick in the seams between stones. A sagging awning frame still\n"
    "clings to a wall.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room252",
    "north" : "/chapter/prologue/area/anshelm/room254",
  ]);

  set_light(1);
}
