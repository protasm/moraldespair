inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Cross";
  long_desc = "Two worn streets cross in a patch of sunken stone. The corners are choked with\nrubble from nearby walls.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room296", "west",
  });
}
