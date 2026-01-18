inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "The lane is quiet and tight, its paving broken in places. Moss spreads along\nthe base of each wall.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room312", "south",
    "domain/original/area/exedoria/room310", "north",
  });
}
