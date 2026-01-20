inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern slave bazaar";
  long_desc = "Eastern slave bazaar.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room732",
    "north" : "/domain/original/area/island/room730",
  ]);

  set_light(1);
}
