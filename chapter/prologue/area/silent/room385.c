inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "The road is scarred with shallow ruts and missing stones. Wind has piled grit\nagainst the surviving curb.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room384",
    "west":"/chapter/prologue/area/silent/room300",
  ]);

  set_light(1);
}
