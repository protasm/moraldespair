inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Blind Cut";
  long_desc = "This tight passage ends in rubble, its floor sunk with dust and mortar. A bricked arch and iron pins suggest a once-used service door.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room814",
    "west":"/chapter/prologue/area/ruined/room/room795",
    "east":"/chapter/prologue/area/ruined/room/room231",
    "north":"/chapter/prologue/area/ruined/room/room961",
  ]);

}
