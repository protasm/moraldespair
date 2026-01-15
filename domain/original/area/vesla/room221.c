inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Hollow Counter";
  long_desc = "A long counter sags under its own weight, split and furred with dust. Behind\n"
              + "it, shelves lie in heaps, and the air is stale and still.\n";
  dest_dir = ({
    "domain/original/area/vesla/room222", "west",
    "domain/original/area/vesla/room220", "east",
    "domain/original/area/vesla/room118", "north",
  });
}
