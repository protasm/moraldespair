inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Outer Gate";
  long_desc =
    "A low arch of stone stands ahead, its carved face worn smooth by rain. Broken\n"
    "cobbles and weeded ruts mark the road leading toward the silent city.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room236", "north",
    "domain/original/area/anshelm/entrance", "exit",
  });

  add_exit_alias("x", "exit");
}
