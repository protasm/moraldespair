inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "High Road";
  long_desc =
    "The road climbs slightly, flanked by taller facades. Broken balcony ironwork\n"
    "hangs over the street.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room265", "south",
    "domain/original/area/anshelm/room267", "north",
  });
}
