inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Abandoned Corner";
  long_desc = "A worn way meets the broader boulevard on a patch of sunken stone and grit here. The junction is scarred by ruts and hollows, with grit swept into the corners.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room196", "west",
    "chapter/prologue/area/ruined/room198", "south",
  });
}

