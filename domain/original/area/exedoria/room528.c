inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "The path is straight and formal, though its stones have shifted. Silent\nfacades rise on both sides.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room896", "south",
    "domain/original/area/exedoria/room894", "east",
    "domain/original/area/exedoria/room527", "north",
  });
}
