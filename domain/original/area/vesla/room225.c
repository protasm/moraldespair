inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Scorched Hearth";
  long_desc = "Soot-dark stone surrounds a dead hearth, the ash long gone.\n"
              + "Crumbling brick and damp stains are all that remain in the\n"
              + "still, cool chamber.\n";
  dest_dir = ({
    "domain/original/area/vesla/room224", "east",
    "domain/original/area/vesla/room122", "north",
  });
}
