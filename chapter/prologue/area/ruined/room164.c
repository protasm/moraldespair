inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The road passes a doorway choked with rubble and ivy. Small pools of rain-dark water stain the stones.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room163",
      "east":"/chapter/prologue/area/ruined/room812",
      "north":"/chapter/prologue/area/ruined/room165",
    ]);

  set_light(1);
}


