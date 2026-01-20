inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Brine Stall";
  long_desc = "Brine has long dried into a crust, leaving the stall rank and silent. Splintered tables and a rusted hook hint at trade in flesh that has since rotted away.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room803", "north",
  });
}
