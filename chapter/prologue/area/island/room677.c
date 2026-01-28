inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Gate House";
  long_desc = "Gate House.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room676",
    "west" : "/chapter/prologue/area/island/room614",
    "east" : "/chapter/prologue/area/island/room693",
    "north" : "/chapter/prologue/area/island/room686",
  ]);

  set_light(1);
}
