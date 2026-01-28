inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room670",
    "west" : "/chapter/prologue/area/island/room662",
    "east" : "/chapter/prologue/area/island/room664",
    "north" : "/chapter/prologue/area/island/room671",
  ]);

  set_light(1);
}
