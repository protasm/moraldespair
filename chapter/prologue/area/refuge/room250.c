inherit "room/room";

void create() {
  ::create();

  short_desc = "East Crossing";
  long_desc =
    "The street opens to a small intersection marked by worn corner stones. Broken\n"
    "shutters hang from a nearby window frame.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room244",
    "east" : "/chapter/prologue/area/refuge/room283",
    "north" : "/chapter/prologue/area/refuge/room251",
  ]);

  set_light(1);
}
