inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Plaza";
  long_desc = "A small plaza opens between low buildings, its paving split by weeds. A dry\nfountain basin lies cracked at its center.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room300",
    "north":"/chapter/prologue/area/silent/room290",
  ]);

  set_light(1);
}
