inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cinder Bay";
  long_desc = "Cold ash and rusted tools lie scattered across a cracked stone floor. A\n"
              + "collapsed bellows and a soot-blackened hearth hint at heat that has not lived\n"
              + "here for centuries.\n";
  dest_dir = ({
    "domain/original/area/vesla/room160", "west",
    "domain/original/area/vesla/room124", "south",
  });
}
