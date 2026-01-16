inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Post";
  long_desc = "A simple post of stone stands abandoned at the corner. Only a cracked bench\nremains inside.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room384", "south",
    "domain/original/area/exedoria/room292", "north",
  });
}
