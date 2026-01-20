inherit "room/room";

void create() {
  ::create();

  short_desc = "Abandoned Corner";
  long_desc = "A worn way meets the broader boulevard on a patch of sunken stone and grit here. The junction is scarred by ruts and hollows, with grit swept into the corners.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room196",
    "south":"/chapter/prologue/area/ruined/room198",
  ]);

  set_light(1);
}

