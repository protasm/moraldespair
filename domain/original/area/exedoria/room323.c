inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Row End";
  long_desc = "The line of grand facades fades into a broken cul-de-sac. A fallen wall spills\ninto the street, blocking the far end.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room317", "west",
    "domain/original/area/exedoria/room324", "north",
  });
}
