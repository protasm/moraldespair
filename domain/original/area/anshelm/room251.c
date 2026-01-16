inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "North Road";
  long_desc =
    "A broad band of stone runs between mute facades. Drifts of grit and leaves\n"
    "gather along the curb.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room250", "south",
    "domain/original/area/anshelm/room1193", "east",
    "domain/original/area/anshelm/room252", "north",
  });
}
