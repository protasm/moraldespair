inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "Cracked paving gives way to patches of dirt and gravel. A few stones still\nhold the line of the old curb.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room305", "east",
    "domain/original/area/exedoria/room307", "west",
  });
}
