inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Bedroom:";
  long_desc = "Bedroom:.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room657",
  ]);

  set_light(1);
}
