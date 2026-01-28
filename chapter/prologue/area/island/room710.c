inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room706",
  ]);

  set_light(1);
}
