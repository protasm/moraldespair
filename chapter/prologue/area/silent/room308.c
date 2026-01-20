inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Lane Start";
  long_desc = "A narrow lane begins between sagging houses. The stones are uneven and broken.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room309", "south",
    "chapter/prologue/area/silent/room307", "north",
  });
}
