inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "The lane runs straight between close walls streaked with damp. A thin line of\ngrass follows the center.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room355", "west",
    "domain/original/area/exedoria/room311", "south",
    "domain/original/area/exedoria/room309", "north",
  });
}
