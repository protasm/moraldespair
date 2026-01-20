inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gray Foyer";
  long_desc = "A gray stone foyer holds a cold stillness. Damp stains stripe the walls from\nfloor to lintel.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room917", "south",
    "chapter/prologue/area/silent/room915", "north",
  });
}
