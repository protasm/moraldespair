inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Post";
  long_desc =
    "A small guard nook overlooks the outer road, its slit windows broken and\n"
    "widened by time. Dusty stone benches remain where sentries once rested.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1136", "up",
    "domain/original/area/anshelm/room237", "northeast",
  });
}
