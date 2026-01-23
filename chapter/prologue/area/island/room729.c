inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern District";
  long_desc = "Eastern District.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room725",
    "south" : "/chapter/prologue/area/island/room730",
  ]);

  set_light(1);
}
