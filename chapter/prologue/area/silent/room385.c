inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "The road is scarred with shallow ruts and missing stones. Wind has piled grit\nagainst the surviving curb.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room384", "east",
    "chapter/prologue/area/silent/room300", "west",
  });

  set_light(1);
}
