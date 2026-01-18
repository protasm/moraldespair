inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Curtain";
  long_desc = "Torn curtains hang in tatters, and dust mats the warped floor boards. A low dais and broken screens hint at a private vice now drowned in mildew.";
  dest_dir = ({
    "domain/original/area/vesla/room802", "south",
  });
}
