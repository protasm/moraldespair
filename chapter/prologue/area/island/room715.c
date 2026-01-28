inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Eastern Chamber";
  long_desc = "Eastern Chamber.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room672",
    "west" : "/chapter/prologue/area/island/room714",
  ]);

  set_light(1);
}
