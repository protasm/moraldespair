inherit "room/room";

void create() {
  ::create();

  short_desc = "Barrack Way";
  long_desc =
    "The street is lined with long foundations and collapsed roofs. Rusted iron\n"
    "hoops lie in the dirt.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room267",
    "east" : "/chapter/prologue/area/refuge/room277",
    "north" : "/chapter/prologue/area/refuge/room1200",
  ]);

  set_light(1);
}
