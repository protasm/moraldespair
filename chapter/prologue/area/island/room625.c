inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "The base of a waterfall";
  long_desc = "The base of a waterfall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room624",
  ]);

  set_light(1);
}
