inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Western Part of Beach";
  long_desc = "Western Part of Beach.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room606",
    "west" : "/chapter/prologue/area/island/room624",
  ]);

  set_light(1);
}
