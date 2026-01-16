inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Flagstone Path";
  long_desc = "Flat stones form a narrow path, each one tilted and cracked. Grass grows thick\nbetween the joints.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room916", "south",
    "domain/original/area/exedoria/room919", "west",
    "domain/original/area/exedoria/room918", "east",
    "domain/original/area/exedoria/room603", "north",
  });
}
