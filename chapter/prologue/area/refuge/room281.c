inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Row";
  long_desc =
    "The lane is straight and silent, edged by worn thresholds. A chipped well cap\n"
    "sits off to one side.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room258",
    "east" : "/chapter/prologue/area/refuge/room1328",
    "north" : "/chapter/prologue/area/refuge/room1197",
  ]);

  set_light(1);
}
