inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room705",
    "east" : "/domain/original/area/island/room706",
    "north" : "/domain/original/area/island/room703",
  ]);

  set_light(1);
}
