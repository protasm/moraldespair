inherit "room/room";

void create() {
  ::create();


  short_desc = "Island Historical Society";
  long_desc = "Island Historical Society.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room664",
    "north" : "/domain/original/area/island/room669",
  ]);

  set_light(1);
}
