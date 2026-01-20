inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "northwest" : "/domain/original/area/island/room719",
    "south" : "/domain/original/area/island/room717",
    "northeast" : "/domain/original/area/island/room718",
    "east" : "/domain/original/area/island/room610",
    "west" : "/domain/original/area/island/room636",
  ]);

  set_light(1);
}
