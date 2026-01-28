inherit "//chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "Northern End";
    long_desc = "The way ends beneath a sagging lintel, the stones split and bowed. A scatter of fallen blocks marks the threshold into the north.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room219",
      "west":"/chapter/prologue/area/ruined/room/room221",
      "east":"/chapter/prologue/area/ruined/room/room233",
      "north":"/chapter/prologue/area/ruined/room/room117",
    ]);

}
