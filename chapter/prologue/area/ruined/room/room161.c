inherit "//chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "Here the main road is flanked by crumbling foundations. A patch of nettles spills across the center line.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room160",
      "east":"/chapter/prologue/area/ruined/room/room808",
      "north":"/chapter/prologue/area/ruined/room/room162",
    ]);

}

