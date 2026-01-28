inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Lady Roland's Bedroom";
  long_desc = "Lady Roland's Bedroom.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room684",
  ]);

  set_light(1);
}
