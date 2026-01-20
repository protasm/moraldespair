inherit "room/room";

void create() {
  ::create();

  short_desc = "Westroad Ruins";
  long_desc = "Westroad runs between low stone shells, their upper courses missing. Fallen blocks lie in the ruts, and a thin growth of grass softens the roadway.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room130",
    "east":"/chapter/prologue/area/ruined/room128",
    "south":"/chapter/prologue/area/ruined/room419",
  ]);

  set_light(1);
}
