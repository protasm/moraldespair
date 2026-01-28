inherit "/chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "A broad road runs north and south, its surface worn into shallow ruts that hold dust and rain marks. Collapsed storefronts sag along the edges, their doorways open to the air.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room116",
      "west":"/chapter/prologue/area/ruined/room/room226",
      "east":"/chapter/prologue/area/ruined/room/room735",
      "north":"/chapter/prologue/area/ruined/room/room173",
    ]);

}

