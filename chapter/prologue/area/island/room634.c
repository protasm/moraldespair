inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "A guard house";
  long_desc = "A guard house.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room609",
  ]);

  set_light(1);
}
