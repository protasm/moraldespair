inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Armoury";
  long_desc = "Armoury.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room631",
    "west" : "/chapter/prologue/area/island/room633",
  ]);

  set_light(1);
}
