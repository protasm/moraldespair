inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Cold Hearth";
  long_desc = "Soot-dark stone surrounds a dead hearth, its ash long blown away. Crumbling brick and damp stains mark the still chamber.";
  dest_dir = ({
    "domain/original/area/vesla/room224", "east",
    "domain/original/area/vesla/room122", "north",
  });
}
