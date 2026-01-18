inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Stone Court";
  long_desc = "Cold stone surrounds this open court, with mildew streaks and fallen chips whitening the ground. A shallow channel in the paving runs toward a broken drain, a remnant of tidy upkeep.";
  dest_dir = ({
    "domain/original/area/vesla/room758", "southeast",
    "domain/original/area/vesla/room757", "south",
    "domain/original/area/vesla/room768", "northeast",
    "domain/original/area/vesla/room765", "east",
    "domain/original/area/vesla/room767", "north",
  });
}
