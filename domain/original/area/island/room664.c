inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room667",
    "west" : "/domain/original/area/island/room663",
    "east" : "/domain/original/area/island/room665",
    "north" : "/domain/original/area/island/room668",
  ]);

  set_light(1);
}
