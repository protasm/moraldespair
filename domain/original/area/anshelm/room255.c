inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Square";
  long_desc =
    "The street widens into a square of mottled stone. A dry basin sits at the\n"
    "center, its rim chipped and stained.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room254", "south",
    "domain/original/area/anshelm/room1195", "west",
    "domain/original/area/anshelm/room1194", "east",
    "domain/original/area/anshelm/room256", "north",
  });
}
