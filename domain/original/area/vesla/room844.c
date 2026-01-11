inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cinder Walk";
  long_desc = "Cinder and gravel crunch over warped flagstones, the walk silent and\n"
        + "dilapidated. Rusting hinges and charred lintels sag in rot and mildew, a dusty\n"
        + "hint of shop doors left in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room842", "south",
    "domain/original/area/vesla/room843", "east",
    "domain/original/area/vesla/room202", "north",
  });
}

