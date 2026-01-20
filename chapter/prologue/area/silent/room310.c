inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "The lane runs straight between close walls streaked with damp. A thin line of\ngrass follows the center.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room355", "west",
    "chapter/prologue/area/silent/room311", "south",
    "chapter/prologue/area/silent/room309", "north",
  });
}
