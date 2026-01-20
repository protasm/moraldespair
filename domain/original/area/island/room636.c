inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "southwest" : "/domain/original/area/island/room722",
    "east" : "/domain/original/area/island/room635",
    "southeast" : "/domain/original/area/island/room721",
    "west" : "/domain/original/area/island/room637",
  ]);

  set_light(1);
}
