inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Weeds press up through the cracked paving stones. Small stones and splinters\nof brick mark where walls fell.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room291",
    "east":"/chapter/prologue/area/silent/room293",
    "south":"/chapter/prologue/area/silent/room383",
  ]);

  set_light(1);
}
