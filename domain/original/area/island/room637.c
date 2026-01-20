inherit "room/room";

void create() {
  ::create();


  short_desc = "West End of Balin Road";
  long_desc = "West End of Balin Road.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room638",
    "northeast" : "/domain/original/area/island/room720",
    "east" : "/domain/original/area/island/room636",
    "south" : "/domain/original/area/island/room723",
  ]);

  set_light(1);
}
