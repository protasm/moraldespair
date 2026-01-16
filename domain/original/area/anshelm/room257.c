inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Row";
  long_desc =
    "Faded plaster clings to the walls in torn patches. A thin vine threads across\n"
    "a cracked arch.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room256", "south",
    "domain/original/area/anshelm/room258", "north",
  });
}
