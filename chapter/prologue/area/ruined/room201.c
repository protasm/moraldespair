inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc = "A narrow run of stone drifts westward, the joints packed with gray silt and moss. A bent iron frame clings to one wall, as if a bell or lantern once marked the passage.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room843", "south",
    "chapter/prologue/area/ruined/room202", "west",
    "chapter/prologue/area/ruined/room200", "east",
  });
}
