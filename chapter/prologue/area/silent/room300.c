inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "A broad road runs between fractured curbstones and toppled markers. The center\nis worn smooth where traffic once passed.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room301",
    "west":"/chapter/prologue/area/silent/room302",
    "east":"/chapter/prologue/area/silent/room385",
    "north":"/chapter/prologue/area/silent/room299",
  ]);

  set_light(1);
}
