inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Curtain";
  long_desc = "Torn curtains hang in tatters, and dust mats the warped floor boards. A low dais and broken screens hint at a private vice now drowned in mildew.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room802",
  ]);

  set_light(1);
}
