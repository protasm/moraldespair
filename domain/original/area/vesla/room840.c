inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Ashen Way";
  long_desc = "Charred stone and blackened beams mark this stretch, now silent and\n"
        + "dilapidated. Ash lies under drifted dust, and mildewed rubble clogs the broken\n"
        + "curb where small fronts once opened in rot and disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room841", "west",
    "domain/original/area/vesla/room148", "south",
  });
}

