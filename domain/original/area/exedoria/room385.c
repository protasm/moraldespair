inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "The road is scarred with shallow ruts and missing stones. Wind has piled grit\nagainst the surviving curb.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room384", "east",
    "domain/original/area/exedoria/room300", "west",
  });
}
