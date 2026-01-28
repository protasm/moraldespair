inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room704",
    "south" : "/chapter/prologue/area/island/room710",
    "north" : "/chapter/prologue/area/island/room707",
  ]);

  set_light(1);
}
