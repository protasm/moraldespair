inherit "room/room";

void create() {
  ::create();

  short_desc = "Outer Gate";
  long_desc =
    "A low arch of stone stands ahead, its carved face worn smooth by rain. Broken\n"
    "cobbles and weeded ruts mark the road leading toward the silent city.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room236", "north",
    "chapter/prologue/area/anshelm/entrance", "exit",
  });

  add_exit_alias("x", "exit");

  set_light(1);
}
