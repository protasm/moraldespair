inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "Old cart ruts cut through the stones, softened by moss. A toppled beam rests across the gutter.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room824",
      "south":"/chapter/prologue/area/ruined/room157",
      "north":"/chapter/prologue/area/ruined/room159",
    ]);

  set_light(1);
}

