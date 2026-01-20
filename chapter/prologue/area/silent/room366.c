inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Shop";
  long_desc = "This narrow shop is lined with empty hooks and dark stains. The air is stale\nand sweet with old rot.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room289", "north",
  });
}
