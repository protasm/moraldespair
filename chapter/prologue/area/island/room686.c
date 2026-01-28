inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "RIIS";
  long_desc = "RIIS.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/island/room687",
    "south" : "/chapter/prologue/area/island/room677",
  ]);

  set_light(1);
}
