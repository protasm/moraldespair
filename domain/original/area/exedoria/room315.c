inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc = "A formal row of buildings rises in matched stone. Windows stare out as dark,\nbroken squares.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room320", "south",
    "domain/original/area/exedoria/room314", "west",
    "domain/original/area/exedoria/room316", "east",
    "domain/original/area/exedoria/room321", "north",
  });
}
