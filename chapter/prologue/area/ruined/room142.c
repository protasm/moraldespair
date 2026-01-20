inherit "room/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "The avenue slopes toward the river quarter, the basalt slick with old stains. A scatter of masonry narrows the passage, leaving the street choked and quiet.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room143",
    "east":"/chapter/prologue/area/ruined/room850",
    "north":"/chapter/prologue/area/ruined/room141",
  ]);

  set_light(1);
}
