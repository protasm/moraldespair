inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Hollow Hall";
  long_desc = "A wide hall yawns under sagging beams, silent and ruined. Dust, mildew, and\n"
        + "rot swallow splintered crates, hinting at bulk storage long abandoned.\n";
  dest_dir = ({
    "domain/original/area/vesla/room198", "west",
  });
}
