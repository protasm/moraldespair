inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Low Hearth";
  long_desc = "The low room smells of damp stone, its beams soft with rot and its floor hidden\n"
              + "beneath dust. A simple table has collapsed beside a cold hearth, and a notched\n"
              + "post stands where some small training once took place.\n";
  dest_dir = ({
    "domain/original/area/vesla/room734", "up",
    "domain/original/area/vesla/room213", "west",
  });
}
