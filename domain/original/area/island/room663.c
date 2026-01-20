inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room670",
    "west" : "/domain/original/area/island/room662",
    "east" : "/domain/original/area/island/room664",
    "north" : "/domain/original/area/island/room671",
  ]);

  set_light(1);
}
