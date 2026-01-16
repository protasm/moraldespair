inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Rotunda";
  long_desc = "A circular chamber rises around a cracked dome. Light spills through gaps\nwhere the roof has fallen.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room376", "west",
  });
}
