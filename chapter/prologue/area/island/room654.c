inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room652",
    "north" : "/chapter/prologue/area/island/room655",
  ]);

  set_light(1);
}
