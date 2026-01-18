inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stair Base";
  long_desc =
    "The base of the eastern stairwell is ringed with fallen tiles. The doorway to\n"
    "the yard stands doorless and warped.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1148", "up",
  });
}
