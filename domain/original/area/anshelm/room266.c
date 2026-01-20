inherit "room/room";

void create() {
  ::create();

  short_desc = "High Road";
  long_desc =
    "The road climbs slightly, flanked by taller facades. Broken balcony ironwork\n"
    "hangs over the street.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room265", "south",
    "domain/original/area/anshelm/room267", "north",
  });

  set_light(1);
}
