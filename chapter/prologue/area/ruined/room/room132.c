inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Westroad Scar";
  long_desc = "A long crack splits the paving, running the length of the road. The break is filled with rubble and silt, and the surrounding stones are polished dull by time.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room133",
    "east":"/chapter/prologue/area/ruined/room/room131",
    "south":"/chapter/prologue/area/ruined/room/room421",
  ]);

}
