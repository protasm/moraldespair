inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Western slave bazaar";
  long_desc = "Western slave bazaar.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room732",
    "north" : "/chapter/prologue/area/island/room727",
  ]);

  set_light(1);
}
