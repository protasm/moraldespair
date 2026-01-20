inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room651",
    "west" : "/domain/original/area/island/room644",
    "east" : "/domain/original/area/island/room649",
    "north" : "/domain/original/area/island/room650",
  ]);

  set_light(1);
}
