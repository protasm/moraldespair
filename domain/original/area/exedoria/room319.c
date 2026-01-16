inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Post";
  long_desc = "A small guard niche sits beside the street, its roof fallen in. A rusted bell\nlies in the debris.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room316", "south",
    "domain/original/area/exedoria/room926", "north",
  });
}
