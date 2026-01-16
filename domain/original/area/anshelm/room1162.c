inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "High Landing";
  long_desc =
    "The landing connects two stairwells, its stone worn smooth. A length of\n"
    "collapsed railing rests against the wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1161", "east",
    "domain/original/area/anshelm/room1163", "down",
  });
}
