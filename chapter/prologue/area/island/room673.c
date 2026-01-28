inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Seed Shop";
  long_desc = "Seed Shop.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room661",
  ]);

  set_light(1);
}
