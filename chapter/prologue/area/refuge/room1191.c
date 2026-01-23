inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Bistro";
  long_desc =
    "Small tables have rotted away, leaving only rusted hooks in the floor. A\n"
    "decorative mirror hangs cracked above a cold hearth.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1190",
    "south" : "/chapter/prologue/area/refuge/room1185",
  ]);

  set_light(1);
}
