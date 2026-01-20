inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Grit-Streaked Crossing";
  long_desc = "Weathered stones mark the meeting of two old streets, their lines softened by drifted grit. A broken post leans over the junction, and no track has passed in generations.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room220", "south",
    "chapter/prologue/area/ruined/room118", "west",
    "chapter/prologue/area/ruined/room116", "east",
    "chapter/prologue/area/ruined/room226", "north",
  });
}
