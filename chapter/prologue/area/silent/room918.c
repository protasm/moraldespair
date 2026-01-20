inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Coach House";
  long_desc = "A wide shed holds the outlines of old stalls. The roof has gaps where light\nfalls through.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room915", "west",
  });
}
