inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Blackened Court";
  long_desc = "The court is a hollow of scorched brick and collapsed awnings, silent and ruined. Mildew blooms on low walls, and rot mixes with dust around broken stalls left to crumble.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room844", "west",
    "chapter/prologue/area/ruined/room841", "south",
    "chapter/prologue/area/ruined/room201", "north",
  });
}
