inherit "room/room";

void create() {
  ::create();

    short_desc = "A dingy alleyway";
    long_desc = "A dingy alleyway";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room410",
      "east":"/chapter/prologue/area/ruined/room795",
      "north":"/chapter/prologue/area/ruined/room794",
    ]);

  set_light(1);
}
