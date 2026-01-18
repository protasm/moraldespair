inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Inner Yard";
  long_desc =
    "The bailey is an open court of broken stone and patches of grass. A low well\n"
    "curb sits dry near the center.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1150", "north",
  });
}
