inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Inner Yard";
  long_desc =
    "The bailey is an open court of broken stone and patches of grass. A low well\n"
    "curb sits dry near the center.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/refuge/room1150",
  ]);

  set_light(1);
}
