inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Broken stones show where wheels once cut a track through the city. Old gutter\nstones run broken and half buried at the sides.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room368",
    "west":"/chapter/prologue/area/silent/room287",
    "east":"/chapter/prologue/area/silent/room289",
    "north":"/chapter/prologue/area/silent/room367",
  ]);

  set_light(1);
}
