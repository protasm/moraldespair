inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Western District";
  long_desc = "Western District.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room728",
    "north" : "/chapter/prologue/area/island/room726",
  ]);

  set_light(1);
}
