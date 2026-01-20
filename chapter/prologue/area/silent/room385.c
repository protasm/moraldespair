inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "The road is scarred with shallow ruts and missing stones. Wind has piled grit\nagainst the surviving curb.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room384", "east",
    "chapter/prologue/area/silent/room300", "west",
  });
}
