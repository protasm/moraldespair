inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sunken Walk";
  long_desc = "The walkway dips into a shallow trough where stones have settled unevenly. A thin film of moss trails along the seams, and the air sits heavy with damp.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room224",
    "west":"/chapter/prologue/area/ruined/room/room122",
    "east":"/chapter/prologue/area/ruined/room/room120",
    "north":"/chapter/prologue/area/ruined/room/room425",
  ]);

}
