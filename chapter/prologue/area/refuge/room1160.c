inherit "room/room";

void create() {
  ::create();

  short_desc = "Small Chamber";
  long_desc =
    "A small chamber opens off the stair, bare and silent. A broken latch hangs\n"
    "from the doorframe.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1159",
    "west" : "/chapter/prologue/area/refuge/room1161",
  ]);

  set_light(1);
}
