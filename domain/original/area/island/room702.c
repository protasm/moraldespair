inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room703",
    "east" : "/domain/original/area/island/room708",
    "north" : "/domain/original/area/island/room701",
  ]);

  set_light(1);
}
