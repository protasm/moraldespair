inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Crossing";
  long_desc =
    "Two streets meet in a small square of cracked paving. An empty fountain base\n"
    "sits crooked against the curb.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room238",
    "west" : "/chapter/prologue/area/anshelm/room414",
    "east" : "/chapter/prologue/area/anshelm/room1185",
    "north" : "/chapter/prologue/area/anshelm/room240",
  ]);

  set_light(1);
}
