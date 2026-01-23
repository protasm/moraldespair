inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Square";
  long_desc =
    "The street widens into a square of mottled stone. A dry basin sits at the\n"
    "center, its rim chipped and stained.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room254",
    "west" : "/chapter/prologue/area/anshelm/room1195",
    "east" : "/chapter/prologue/area/anshelm/room1194",
    "north" : "/chapter/prologue/area/anshelm/room256",
  ]);

  set_light(1);
}
