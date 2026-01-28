inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "South Corridor";
  long_desc = "South Corridor.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room695",
    "north" : "/chapter/prologue/area/island/room693",
  ]);

  set_light(1);
}
