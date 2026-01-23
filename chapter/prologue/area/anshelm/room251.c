inherit "room/room";

void create() {
  ::create();

  short_desc = "North Road";
  long_desc =
    "A broad band of stone runs between mute facades. Drifts of grit and leaves\n"
    "gather along the curb.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room250",
    "east" : "/chapter/prologue/area/anshelm/room1193",
    "north" : "/chapter/prologue/area/anshelm/room252",
  ]);

  set_light(1);
}
