inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Hollow Walk";
  long_desc = "A hollowed stretch of passage runs between damp stone walls. The roof timbers\n"
              + "have fallen away, leaving the corridor open to dull light and slow rain.\n";
  dest_dir = ({
    "domain/original/area/vesla/room121", "west",
    "domain/original/area/vesla/room119", "east",
    "domain/original/area/vesla/room223", "south",
  });
}
