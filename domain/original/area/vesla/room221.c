inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Forgotten Counter";
  long_desc = "A long counter lies warped and split, its surface powdered\n"
              + "with dust. Fallen shelves clutter the walls, and the air\n"
              + "hangs stale and undisturbed.\n";
  dest_dir = ({
    "domain/original/area/vesla/room222", "west",
    "domain/original/area/vesla/room220", "east",
    "domain/original/area/vesla/room118", "north",
  });
}
