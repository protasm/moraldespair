inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "A stone walk runs between broad buildings with blank windows. Leaves gather in\nshallow drifts along the edges.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room528",
    "north":"/chapter/prologue/area/silent/room387",
  ]);

  set_light(1);
}
