inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible";
  long_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room713",
  ]);

  set_light(1);
}
