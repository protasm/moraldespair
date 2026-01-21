inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Lane";
  long_desc = "The lane is quiet and tight, its paving broken in places. Moss spreads along\nthe base of each wall.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room312",
    "north":"/chapter/prologue/area/silent/room310",
  ]);

  set_light(1);
}
