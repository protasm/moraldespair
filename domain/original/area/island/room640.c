inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room657",
    "east" : "/domain/original/area/island/room639",
    "north" : "/domain/original/area/island/room641",
  ]);

  set_light(1);
}
