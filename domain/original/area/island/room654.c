inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room652",
    "north" : "/domain/original/area/island/room655",
  ]);

  set_light(1);
}
