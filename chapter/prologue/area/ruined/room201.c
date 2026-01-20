inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Way";
  long_desc = "A narrow run of stone drifts westward, the joints packed with gray silt and moss. A bent iron frame clings to one wall, as if a bell or lantern once marked the passage.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room843",
    "west":"/chapter/prologue/area/ruined/room202",
    "east":"/chapter/prologue/area/ruined/room200",
  ]);

  set_light(1);
}
