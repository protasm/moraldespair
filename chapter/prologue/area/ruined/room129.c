inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Ruins";
  long_desc = "Westroad runs between low stone shells, their upper courses missing. Fallen blocks lie in the ruts, and a thin growth of grass softens the roadway.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room130", "west",
    "chapter/prologue/area/ruined/room128", "east",
    "chapter/prologue/area/ruined/room419", "south",
  });
}
