inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The northward main road rises slightly, its stones pale and chipped. A cold breeze funnels through the gap between empty facades.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room125",
      "east":"/chapter/prologue/area/ruined/room412",
      "north":"/chapter/prologue/area/ruined/room161",
    ]);

  set_light(1);
}

