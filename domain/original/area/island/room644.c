inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room643",
    "west" : "/domain/original/area/island/room646",
    "east" : "/domain/original/area/island/room648",
    "north" : "/domain/original/area/island/room645",
  ]);

  set_light(1);
}
