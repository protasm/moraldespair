inherit "room/room";

void create() {
  ::create();

  short_desc = "Gravel Cross";
  long_desc = "Gravel paths meet in a small clearing of trampled stone. One branch is almost\nlost beneath grass.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room379",
    "southeast":"/chapter/prologue/area/silent/room382",
    "north":"/chapter/prologue/area/silent/room381",
  ]);

  set_light(1);
}
