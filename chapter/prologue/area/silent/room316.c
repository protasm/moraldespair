inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Row";
  long_desc = "Wide steps front each entrance, all worn to hollows. Rain has streaked the\ncarved lintels.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room318",
    "west":"/chapter/prologue/area/silent/room315",
    "east":"/chapter/prologue/area/silent/room317",
    "north":"/chapter/prologue/area/silent/room319",
  ]);

  set_light(1);
}
