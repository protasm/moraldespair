inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room647",
    "east" : "/domain/original/area/island/room642",
    "north" : "/domain/original/area/island/room644",
  ]);

  set_light(1);
}
