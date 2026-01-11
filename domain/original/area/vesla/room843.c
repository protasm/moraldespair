inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Blackened Court";
  long_desc = "The court is a hollow of scorched brick and collapsed awnings, silent and\n"
        + "ruined. Mildew blooms on low walls, and rot mixes with dust around broken\n"
        + "stalls left to crumble.\n";
  dest_dir = ({
    "domain/original/area/vesla/room844", "west",
    "domain/original/area/vesla/room841", "south",
    "domain/original/area/vesla/room201", "north",
  });
}
