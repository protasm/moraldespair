inherit "room/room";

void create() {
  ::create();


  short_desc = "East End of Balin Road";
  long_desc = "East End of Balin Road.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room664",
    "south" : "/domain/original/area/island/room666",
  ]);

  set_light(1);
}
