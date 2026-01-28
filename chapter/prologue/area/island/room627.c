inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Eastern Beach";
  long_desc = "Eastern Beach.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room626",
  ]);

  set_light(1);
}
