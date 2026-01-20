inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Flagstone Path";
  long_desc = "Flat stones form a narrow path, each one tilted and cracked. Grass grows thick\nbetween the joints.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room916", "south",
    "chapter/prologue/area/silent/room919", "west",
    "chapter/prologue/area/silent/room918", "east",
    "chapter/prologue/area/silent/room603", "north",
  });
}
