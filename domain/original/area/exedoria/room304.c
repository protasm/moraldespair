inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "The roadbed dips where the ground has settled. Broken walls crowd close on\neither side.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room305", "west",
    "domain/original/area/exedoria/room303", "east",
    "domain/original/area/exedoria/room330", "north",
  });
}
