inherit "room/room";

void create() {
  ::create();


  short_desc = "Western District";
  long_desc = "Western District.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room728",
    "north" : "/domain/original/area/island/room726",
  ]);

  set_light(1);
}
