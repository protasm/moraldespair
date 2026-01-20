inherit "room/room";

void create() {
  ::create();

  short_desc = "Row Start";
  long_desc = "Tall facades begin along the street, their windows hollow. The paving here is\ncleaner, though still cracked.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room314", "east",
    "chapter/prologue/area/silent/room312", "north",
  });

  set_light(1);
}
