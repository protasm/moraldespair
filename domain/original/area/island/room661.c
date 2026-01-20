inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room660",
    "east" : "/domain/original/area/island/room662",
    "south" : "/domain/original/area/island/room673",
  ]);

  set_light(1);
}
