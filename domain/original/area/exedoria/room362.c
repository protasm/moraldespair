inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cobble Hall";
  long_desc = "A cobbled corridor runs straight beneath a low ceiling. Water has darkened the\nstones near the edges.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room356", "south",
    "domain/original/area/exedoria/room363", "east",
    "domain/original/area/exedoria/room364", "north",
  });
}
