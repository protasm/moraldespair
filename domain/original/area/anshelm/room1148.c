inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Steps";
  long_desc =
    "Stone steps climb within the eastern tower, their edges worn thin. A trickle\n"
    "of water runs down one wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1149", "down",
  });
}
