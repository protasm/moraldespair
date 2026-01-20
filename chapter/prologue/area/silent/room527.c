inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "A stone walk runs between broad buildings with blank windows. Leaves gather in\nshallow drifts along the edges.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room528", "south",
    "chapter/prologue/area/silent/room387", "north",
  });
}
