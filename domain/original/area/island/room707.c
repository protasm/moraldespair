inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room703",
    "south" : "/domain/original/area/island/room706",
    "north" : "/domain/original/area/island/room708",
  ]);

  set_light(1);
}
