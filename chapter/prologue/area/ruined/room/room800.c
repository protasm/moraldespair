inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Rot Cut";
  long_desc = "The alley widens slightly, filled with rotting boards and a soft bed of dust. A leaning beam and iron staple suggest a former stall or screen.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room799",
    "east":"/chapter/prologue/area/ruined/room/room801",
    "north":"/chapter/prologue/area/ruined/room/room806",
  ]);

}
