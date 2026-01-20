inherit "room/room";

void create() {
  ::create();

  short_desc = "Coach House";
  long_desc = "A wide shed holds the outlines of old stalls. The roof has gaps where light\nfalls through.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room915", "west",
  });

  set_light(1);
}
