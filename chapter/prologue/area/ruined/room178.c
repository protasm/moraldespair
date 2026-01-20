inherit "room/room";

void create() {
  ::create();

    short_desc = "Darkened Crossing";
    long_desc = "Two streets meet in a spread of fractured stone, their lines still clear beneath the dust. A collapsed corner wall exposes a dark room open to the weather.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room185",
      "south":"/chapter/prologue/area/ruined/room177",
      "north":"/chapter/prologue/area/ruined/room179",
    ]);

  set_light(1);
}

