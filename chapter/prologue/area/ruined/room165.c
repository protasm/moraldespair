inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The north road levels out and grows quiet, its surface scabbed with grit. A cracked iron grate lies in the gutter.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room164",
      "north":"/chapter/prologue/area/ruined/room166",
    ]);

  set_light(1);
}

