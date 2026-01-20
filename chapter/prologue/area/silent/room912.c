inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Wood Hall";
  long_desc = "A hallway lined with wooden beams runs between stone walls. The boards are\nwarped and dark with age.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room913", "east",
    "chapter/prologue/area/silent/room909", "west",
  });
}
