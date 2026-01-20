inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Row Start";
  long_desc = "Tall facades begin along the street, their windows hollow. The paving here is\ncleaner, though still cracked.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room314", "east",
    "chapter/prologue/area/silent/room312", "north",
  });
}
