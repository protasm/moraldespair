inherit "room/room";

void create() {
  ::create();


  short_desc = "Western slave bazaar";
  long_desc = "Western slave bazaar.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room732",
    "north" : "/domain/original/area/island/room727",
  ]);

  set_light(1);
}
