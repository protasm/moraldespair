inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Water has eaten shallow channels along the roadbed. Windblown dust gathers in\nthe ruts where traffic once passed.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room298", "south",
    "chapter/prologue/area/silent/room290", "west",
    "chapter/prologue/area/silent/room292", "east",
    "chapter/prologue/area/silent/room370", "north",
  });
}
