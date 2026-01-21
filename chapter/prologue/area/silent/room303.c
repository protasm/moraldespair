inherit "room/room";

void create() {
  ::create();

  short_desc = "Road Middle";
  long_desc = "The road runs straight between broken foundations. Dust and grit have buried\nthe old curb.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room304",
    "east":"/chapter/prologue/area/silent/room302",
    "south":"/chapter/prologue/area/silent/room329",
  ]);

  set_light(1);
}
