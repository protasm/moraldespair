inherit "room/room";

void create() {
  ::create();

    short_desc = "Northern End";
    long_desc = "The way ends beneath a sagging lintel, the stones split and bowed. A scatter of fallen blocks marks the threshold into the north.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room219",
      "west":"/chapter/prologue/area/ruined/room221",
      "east":"/chapter/prologue/area/ruined/room233",
      "north":"/chapter/prologue/area/ruined/room117",
    ]);

  set_light(1);
}
