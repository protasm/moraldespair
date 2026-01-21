inherit "room/room";

void create() {
  ::create();

  short_desc = "Cobble Hall";
  long_desc = "Round cobbles form the hall floor, slick with age. The walls narrow as the\ncorridor stretches on.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room358",
    "east":"/chapter/prologue/area/silent/room360",
    "north":"/chapter/prologue/area/silent/room356",
  ]);

  set_light(1);
}
