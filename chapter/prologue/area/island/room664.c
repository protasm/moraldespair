inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room667",
    "west" : "/chapter/prologue/area/island/room663",
    "east" : "/chapter/prologue/area/island/room665",
    "north" : "/chapter/prologue/area/island/room668",
  ]);

  set_light(1);
}
