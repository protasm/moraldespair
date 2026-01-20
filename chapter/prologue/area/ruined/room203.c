inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Way";
  long_desc = "The street has sagged and cracked, letting patches of weeds break through the seams. A fallen crossbeam lies against the wall, its fittings scarred as if something once hung there and rang.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room202",
    "west":"/chapter/prologue/area/ruined/room204",
  ]);

  set_light(1);
}
