inherit "room/room";

void create() {
  ::create();

    short_desc = "Main Wall Crossing";
    long_desc = "The crossing is wide and empty, marked by worn paving and shallow ruts. A broken curb rings the corner where the streets meet.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room167",
      "west":"/chapter/prologue/area/ruined/room793",
      "east":"/chapter/prologue/area/ruined/room170",
      "north":"/chapter/prologue/area/ruined/room169",
    ]);

  set_light(1);
}

