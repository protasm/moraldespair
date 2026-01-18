inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Abandoned Corner";
  long_desc = "A worn way meets the broader boulevard on a patch of sunken stone and grit here. The junction is scarred by ruts and hollows, with grit swept into the corners.";
  dest_dir = ({
    "domain/original/area/vesla/room196", "west",
    "domain/original/area/vesla/room198", "south",
  });
}

