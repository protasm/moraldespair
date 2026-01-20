inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room661",
    "west" : "/domain/original/area/island/room610",
  ]);

  set_light(1);
}
