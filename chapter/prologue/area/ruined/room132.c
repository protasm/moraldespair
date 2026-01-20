inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Scar";
  long_desc = "A long crack splits the paving, running the length of the road. The break is filled with rubble and silt, and the surrounding stones are polished dull by time.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room133", "west",
    "chapter/prologue/area/ruined/room131", "east",
    "chapter/prologue/area/ruined/room421", "south",
  });
}
