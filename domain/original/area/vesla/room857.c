inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Hollow Hall";
  long_desc = "A wide hall yawns under sagging beams, silent and dilapidated. Dust, mildew,\n"
        + "and rot swallow splintered crates, hinting at bulk storage left in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room198", "west",
  });
}

