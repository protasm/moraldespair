inherit "room/room";

void create() {
  ::create();


  short_desc = "A desert plain";
  long_desc = "A desert plain.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room628",
    "north" : "/domain/original/area/island/room630",
  ]);

  set_light(1);
}
