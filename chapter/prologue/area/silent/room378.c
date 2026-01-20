inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gravel Walk";
  long_desc = "A gravel path winds toward a distant, pale structure. Pebbles crunch in the\nwind where weeds have not taken hold.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room379", "east",
    "chapter/prologue/area/silent/room371", "west",
  });
}
