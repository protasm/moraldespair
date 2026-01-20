inherit "room/room";

void create() {
  ::create();

    short_desc = "Silted Run";
    long_desc = "A narrow run between stalls is choked with silt and crumbled wood. The rails are split, and the stone base is slick with moss.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room784",
      "west":"/chapter/prologue/area/ruined/room774",
      "east":"/chapter/prologue/area/ruined/room776",
      "north":"/chapter/prologue/area/ruined/room785",
    ]);

  set_light(1);
}

