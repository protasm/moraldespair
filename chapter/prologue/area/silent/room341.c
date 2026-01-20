inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Street";
  long_desc = "The stone street runs toward a tangle of fallen masonry. Its edges are\nsoftened by drifted soil and grass.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room340", "west",
    "chapter/prologue/area/silent/room342", "north",
  });
}
