inherit "room/room";

void create() {
  ::create();

  short_desc = "Flagstone Entry";
  long_desc = "Flat stones form a short entry that has sunk into the ground. Weeds push\nthrough every seam.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room915",
    "north":"/chapter/prologue/area/silent/room337",
  ]);

  set_light(1);
}
