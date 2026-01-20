inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern District";
  long_desc = "Eastern District.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room725",
    "south" : "/domain/original/area/island/room730",
  ]);

  set_light(1);
}
