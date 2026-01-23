inherit "room/room";

void create() {
  ::create();


  short_desc = "East End of Balin Road";
  long_desc = "East End of Balin Road.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room664",
    "south" : "/chapter/prologue/area/island/room666",
  ]);

  set_light(1);
}
