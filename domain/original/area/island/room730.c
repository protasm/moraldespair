inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern District";
  long_desc = "Eastern District.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room731",
    "north" : "/domain/original/area/island/room729",
  ]);

  set_light(1);
}
