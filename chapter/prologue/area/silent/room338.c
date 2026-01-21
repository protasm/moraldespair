inherit "room/room";

void create() {
  ::create();

  short_desc = "East Bridge";
  long_desc = "A narrow stone bridge spans a shallow, weed-choked channel. Several stones are\nmissing, leaving gaps that show the water below.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room337",
    "east":"/chapter/prologue/area/silent/room339",
    "north":"/chapter/prologue/area/silent/room604",
  ]);

  set_light(1);
}
