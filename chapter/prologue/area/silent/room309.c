inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Lane";
  long_desc = "A narrow lane winds between close houses with shuttered windows. Damp stains\nstripe the stone.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room310",
    "north":"/chapter/prologue/area/silent/room308",
  ]);

  set_light(1);
}
