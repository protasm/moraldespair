inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Workshop";
  long_desc = "A heavy room holds idle mechanisms, their belts long rotted away. Oil stains\nand rust mark the floor.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room929", "down",
  });
}
