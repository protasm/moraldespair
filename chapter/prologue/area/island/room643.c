inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room647",
    "east" : "/chapter/prologue/area/island/room642",
    "north" : "/chapter/prologue/area/island/room644",
  ]);

  set_light(1);
}
