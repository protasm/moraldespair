inherit "room/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room661",
    "east" : "/chapter/prologue/area/island/room663",
    "north" : "/chapter/prologue/area/island/room672",
  ]);

  set_light(1);
}
