inherit "room/room";

void create() {
  ::create();


  short_desc = "Western District";
  long_desc = "Western District.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room725",
    "south" : "/chapter/prologue/area/island/room727",
  ]);

  set_light(1);
}
