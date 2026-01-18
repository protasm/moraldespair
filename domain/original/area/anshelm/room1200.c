inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Works";
  long_desc =
    "An unfinished structure lies open to the weather, its walls buckled. Bundles\n"
    "of warped timber rot along the edges.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room276", "south",
  });
}
