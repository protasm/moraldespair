inherit "/chapter/prologue/std/room";

void create() {
  ::create();

    short_desc = "Hollow Park";
    long_desc = "The ground dips where a pond once spread, now a dish of silt and weeds. Scattered paving stones and toppled posts mark the forgotten walkway.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room/room226",
      "west":"/chapter/prologue/area/ruined/room/room228",
      "east":"/chapter/prologue/area/ruined/room/room173",
      "north":"/chapter/prologue/area/ruined/room/room234",
    ]);

}
