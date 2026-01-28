inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Council Chamber";
  long_desc = "Council Chamber.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room681",
    "west" : "/chapter/prologue/area/island/room683",
  ]);

  set_light(1);
}
