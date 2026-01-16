inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Soot Cut";
  long_desc = "Soot-blackened stone closes in here, and the air is still and\n"
    "stale. A broken lintel and splintered frame imply a long-removed\n"
    "gate.\n";
  dest_dir = ({
    "domain/original/area/vesla/room795", "south",
    "domain/original/area/vesla/room798", "north",
  });
}
