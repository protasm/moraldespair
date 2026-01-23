inherit "room/room";

void create() {
  ::create();


  short_desc = "Island Historical Society";
  long_desc = "Island Historical Society.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room664",
    "north" : "/chapter/prologue/area/island/room669",
  ]);

  set_light(1);
}
