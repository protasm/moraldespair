inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Coach House";
  long_desc = "A wide shed holds the outlines of old stalls. The roof has gaps where light\nfalls through.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room915", "west",
  });
}
