inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Lane";
  long_desc = "The lane is quiet and tight, its paving broken in places. Moss spreads along\nthe base of each wall.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room312", "south",
    "chapter/prologue/area/silent/room310", "north",
  });
}
