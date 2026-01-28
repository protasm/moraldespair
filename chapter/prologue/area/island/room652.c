inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room653",
    "east" : "/chapter/prologue/area/island/room650",
    "north" : "/chapter/prologue/area/island/room654",
  ]);

  set_light(1);
}
