inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room661",
    "west" : "/chapter/prologue/area/island/room610",
  ]);

  set_light(1);
}
