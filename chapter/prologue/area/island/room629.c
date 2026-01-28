inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "A desert plain";
  long_desc = "A desert plain.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room628",
    "north" : "/chapter/prologue/area/island/room630",
  ]);

  set_light(1);
}
