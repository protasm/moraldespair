inherit "room/room";

void create() {
  ::create();


  short_desc = "Guard Room";
  long_desc = "Guard Room.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room609",
    "west" : "/domain/original/area/island/room632",
  ]);

  set_light(1);
}
