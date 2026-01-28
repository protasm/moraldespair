inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room640",
    "north" : "/chapter/prologue/area/island/room642",
  ]);

  set_light(1);
}
