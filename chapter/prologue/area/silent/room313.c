inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Row Start";
  long_desc = "Tall facades begin along the street, their windows hollow. The paving here is\ncleaner, though still cracked.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room314",
    "north":"/chapter/prologue/area/silent/room312",
  ]);

  set_light(1);
}
