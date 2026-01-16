inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dusty Way";
  long_desc =
    "Dust lies thick in the seams between stones. A sagging awning frame still\n"
    "clings to a wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room252", "south",
    "domain/original/area/anshelm/room254", "north",
  });
}
