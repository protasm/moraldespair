inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Row Start";
  long_desc = "Tall facades begin along the street, their windows hollow. The paving here is\ncleaner, though still cracked.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room314", "east",
    "domain/original/area/exedoria/room312", "north",
  });
}
