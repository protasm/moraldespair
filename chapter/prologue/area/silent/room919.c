inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Low Quarters";
  long_desc = "A low-ceilinged room is divided into narrow cubbies. The partitions are warped\nand splintered.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room915", "east",
  });
}
