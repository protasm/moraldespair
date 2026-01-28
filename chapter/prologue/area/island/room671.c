inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Temple Shop";
  long_desc = "Temple Shop.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room672",
    "south" : "/chapter/prologue/area/island/room663",
  ]);

  set_light(1);
}
