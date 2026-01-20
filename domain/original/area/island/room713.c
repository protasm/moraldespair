inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple";
  long_desc = "Temple.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room611",
    "east" : "/domain/original/area/island/room714",
    "north" : "/domain/original/area/island/room716",
  ]);

  set_light(1);
}
