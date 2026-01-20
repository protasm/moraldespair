inherit "room/room";

void create() {
  ::create();

    short_desc = "Withered Park";
    long_desc = "Dry shrubs crowd a cracked path, and pale trunks stand stripped of bark. Old lantern hooks hang crooked from a low wall, black with rust.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room230",
      "west":"/chapter/prologue/area/ruined/room796",
      "east":"/chapter/prologue/area/ruined/room228",
      "north":"/chapter/prologue/area/ruined/room426",
    ]);

  set_light(1);
}
