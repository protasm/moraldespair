inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Row";
  long_desc =
    "Faded plaster clings to the walls in torn patches. A thin vine threads across\n"
    "a cracked arch.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room256", "south",
    "chapter/prologue/area/anshelm/room258", "north",
  });

  set_light(1);
}
