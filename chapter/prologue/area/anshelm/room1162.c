inherit "room/room";

void create() {
  ::create();

  short_desc = "High Landing";
  long_desc =
    "The landing connects two stairwells, its stone worn smooth. A length of\n"
    "collapsed railing rests against the wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1161", "east",
    "chapter/prologue/area/anshelm/room1163", "down",
  });

  set_light(1);
}
