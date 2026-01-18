inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruin Lot";
  long_desc =
    "A pit of rubble and half-set stone marks an abandoned build. Weeds knot around\n"
    "a snapped beam.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room271", "south",
  });
}
