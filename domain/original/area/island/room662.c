inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room661",
    "east" : "/domain/original/area/island/room663",
    "north" : "/domain/original/area/island/room672",
  ]);

  set_light(1);
}
