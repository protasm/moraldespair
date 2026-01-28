inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Eastern slave bazaar";
  long_desc = "Eastern slave bazaar.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room732",
    "north" : "/chapter/prologue/area/island/room730",
  ]);

  set_light(1);
}
