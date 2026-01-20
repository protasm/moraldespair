inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Row End";
  long_desc = "The line of grand facades fades into a broken cul-de-sac. A fallen wall spills\ninto the street, blocking the far end.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room317", "west",
    "chapter/prologue/area/silent/room324", "north",
  });
}
