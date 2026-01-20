inherit "room/room";

void create() {
  ::create();

  short_desc = "North Road";
  long_desc =
    "A broad band of stone runs between mute facades. Drifts of grit and leaves\n"
    "gather along the curb.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room250", "south",
    "chapter/prologue/area/anshelm/room1193", "east",
    "chapter/prologue/area/anshelm/room252", "north",
  });

  set_light(1);
}
