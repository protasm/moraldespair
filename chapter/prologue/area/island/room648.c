inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room651",
    "west" : "/chapter/prologue/area/island/room644",
    "east" : "/chapter/prologue/area/island/room649",
    "north" : "/chapter/prologue/area/island/room650",
  ]);

  set_light(1);
}
