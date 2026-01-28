inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "City Pastry Shop";
  long_desc = "City Pastry Shop.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room612",
  ]);

  set_light(1);
}
