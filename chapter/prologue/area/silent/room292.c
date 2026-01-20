inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Weeds press up through the cracked paving stones. Small stones and splinters\nof brick mark where walls fell.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room291", "west",
    "chapter/prologue/area/silent/room293", "east",
    "chapter/prologue/area/silent/room383", "south",
  });

  set_light(1);
}
