inherit "room/room";

void create() {
  ::create();

  short_desc = "Back Lane";
  long_desc =
    "A small lane winds between cramped houses. Broken shutters lie in the weeds.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/anshelm/room250",
    "east" : "/chapter/prologue/area/anshelm/room284",
    "north" : "/chapter/prologue/area/anshelm/room1326",
  ]);

  set_light(1);
}
