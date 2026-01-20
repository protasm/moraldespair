inherit "room/room";

void create() {
  ::create();

    short_desc = "Hollow Park";
    long_desc = "The ground dips where a pond once spread, now a dish of silt and weeds. Scattered paving stones and toppled posts mark the forgotten walkway.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room226",
      "west":"/chapter/prologue/area/ruined/room228",
      "east":"/chapter/prologue/area/ruined/room173",
      "north":"/chapter/prologue/area/ruined/room234",
    ]);

  set_light(1);
}
