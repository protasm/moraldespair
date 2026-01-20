inherit "room/room";

void create() {
  ::create();


  short_desc = "Central slave bazaar";
  long_desc = "Central slave bazaar.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room728",
    "east" : "/domain/original/area/island/room731",
    "south" : "/domain/original/area/island/room733",
  ]);

  set_light(1);
}
