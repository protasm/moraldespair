inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Fallen Shrine";
  long_desc = "Stone benches sit in crooked rows, their edges rounded by damp and rot.\n"
              + "A shallow brazier lies overturned near the front, its iron scaled with rust and\n"
              + "its embers long gone.\n";
  dest_dir = ({
    "domain/original/area/vesla/room404", "west",
    "domain/original/area/vesla/room407", "south",
    "domain/original/area/vesla/room406", "north",
  });
}
