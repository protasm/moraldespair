inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Fallen Shrine";
  long_desc = "Stone benches sit in crooked rows, their edges rounded by damp and rot. A shallow brazier lies overturned near the front, its iron scaled with rust and its embers long gone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room404", "west",
    "chapter/prologue/area/ruined/room407", "south",
    "chapter/prologue/area/ruined/room406", "north",
  });
}
