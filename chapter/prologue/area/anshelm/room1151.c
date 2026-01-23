inherit "room/room";

void create() {
  ::create();

  short_desc = "East Stair";
  long_desc =
    "The stairwell narrows as it rises, with crumbling plaster exposing rough\n"
    "stone. Iron nails protrude where a railing once stood.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/anshelm/room1149",
    "up" : "/chapter/prologue/area/anshelm/room1152",
  ]);

  set_light(1);
}
