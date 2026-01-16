inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Abandoned Corner";
  long_desc = "Rapier Way meets a broader boulevard on a patch of sunken stone and grit here.\n"
              + "The junction is scarred by ruts and hollows, with grit swept into the corners.\n";
  dest_dir = ({
    "domain/original/area/vesla/room196", "west",
    "domain/original/area/vesla/room198", "south",
  });
}

