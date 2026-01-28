inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Temple";
  long_desc = "Temple.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room611",
    "east" : "/chapter/prologue/area/island/room714",
    "north" : "/chapter/prologue/area/island/room716",
  ]);

  set_light(1);
}
