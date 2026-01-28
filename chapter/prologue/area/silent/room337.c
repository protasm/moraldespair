inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "Cracked paving leads past shuttered houses with sagging roofs. Grass grows in\na thin line along the middle.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room336",
    "east":"/chapter/prologue/area/silent/room338",
    "south":"/chapter/prologue/area/silent/room603",
  ]);

  set_light(1);
}
