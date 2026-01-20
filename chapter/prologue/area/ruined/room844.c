inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cinder Walk";
  long_desc = "Cinder and gravel crunch over warped flagstones, the walk silent and weathered. Rusting hinges and charred lintels sag in rot and mildew, a dusty hint of shop doors left to decay.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room842", "south",
    "chapter/prologue/area/ruined/room843", "east",
    "chapter/prologue/area/ruined/room202", "north",
  });
}
