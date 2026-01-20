inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken Walk";
  long_desc = "The walkway dips into a shallow trough where stones have settled unevenly. A thin film of moss trails along the seams, and the air sits heavy with damp.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room224", "south",
    "chapter/prologue/area/ruined/room122", "west",
    "chapter/prologue/area/ruined/room120", "east",
    "chapter/prologue/area/ruined/room425", "north",
  });
}
