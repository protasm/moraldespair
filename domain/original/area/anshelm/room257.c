inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Row";
  long_desc =
    "Faded plaster clings to the walls in torn patches. A thin vine threads across\n"
    "a cracked arch.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room256", "south",
    "domain/original/area/anshelm/room258", "north",
  });

  set_light(1);
}
