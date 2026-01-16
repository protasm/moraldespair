inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Walk";
  long_desc = "A stone walk runs between broad buildings with blank windows. Leaves gather in\nshallow drifts along the edges.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room528", "south",
    "domain/original/area/exedoria/room387", "north",
  });
}
