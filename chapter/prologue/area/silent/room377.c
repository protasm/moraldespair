inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Rotunda";
  long_desc = "A circular chamber rises around a cracked dome. Light spills through gaps\nwhere the roof has fallen.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room376", "west",
  });
}
