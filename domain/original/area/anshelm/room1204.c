inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Hall";
  long_desc =
    "A wide chamber opens in the keep, its floor swept bare by wind. A carved niche\n"
    "stands empty above a cracked ledge.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1143", "east",
  });
}
