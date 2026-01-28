inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room704",
    "east" : "/chapter/prologue/area/island/room707",
    "north" : "/chapter/prologue/area/island/room702",
  ]);

  set_light(1);
}
