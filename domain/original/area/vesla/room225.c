inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Cold Hearth";
  long_desc = "Soot-dark stone surrounds a dead hearth, its ash long\n"
              + "blown away.\n"
              + "Crumbling brick and damp stains mark the still chamber.\n";
  dest_dir = ({
    "domain/original/area/vesla/room224", "east",
    "domain/original/area/vesla/room122", "north",
  });
}
