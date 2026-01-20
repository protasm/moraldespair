inherit "room/room";

void create() {
  ::create();


  short_desc = "South Corridor";
  long_desc = "South Corridor.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room695",
    "north" : "/domain/original/area/island/room693",
  ]);

  set_light(1);
}
