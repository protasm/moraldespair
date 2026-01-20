inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Home";
  long_desc = "Dwarven Home.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room652",
    "south" : "/domain/original/area/island/room656",
  ]);

  set_light(1);
}
