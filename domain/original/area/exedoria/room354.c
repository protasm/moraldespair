inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Walls";
  long_desc = "Fragments of wall stand like ribs around a roofless room. The open sky looks\ndown on rubble and weeds.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room312", "east",
  });
}
