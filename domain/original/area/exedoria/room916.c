inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gray Foyer";
  long_desc = "A gray stone foyer holds a cold stillness. Damp stains stripe the walls from\nfloor to lintel.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room917", "south",
    "domain/original/area/exedoria/room915", "north",
  });
}
