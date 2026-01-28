inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Alchemist Shop";
  long_desc = "Alchemist Shop.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room616",
  ]);

  set_light(1);
}
