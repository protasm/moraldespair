inherit "/room/room";

void create() {
  ::create();

  short_desc = "High Landing";
  long_desc =
    "The landing connects two stairwells, its stone worn smooth. A length of\n"
    "collapsed railing rests against the wall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1161",
    "down" : "/chapter/prologue/area/refuge/room1163",
  ]);

  set_light(1);
}
