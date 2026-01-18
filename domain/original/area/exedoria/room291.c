inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Water has eaten shallow channels along the roadbed. Windblown dust gathers in\nthe ruts where traffic once passed.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room298", "south",
    "domain/original/area/exedoria/room290", "west",
    "domain/original/area/exedoria/room292", "east",
    "domain/original/area/exedoria/room370", "north",
  });
}
