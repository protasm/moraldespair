inherit "room/room";

void create() {
  ::create();

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room802",
      "south":"/chapter/prologue/area/ruined/room804",
    ]);

  set_light(1);
}
