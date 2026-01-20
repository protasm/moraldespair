inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Low Hearth";
  long_desc = "The low room smells of damp stone, its beams soft with rot and its floor hidden beneath dust. A simple table has collapsed beside a cold hearth, and a notched post stands where some small training once took place.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room734", "up",
    "chapter/prologue/area/ruined/room213", "west",
  });
}
