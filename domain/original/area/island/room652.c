inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room653",
    "east" : "/domain/original/area/island/room650",
    "north" : "/domain/original/area/island/room654",
  ]);

  set_light(1);
}
