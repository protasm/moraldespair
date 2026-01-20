inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room704",
    "east" : "/domain/original/area/island/room707",
    "north" : "/domain/original/area/island/room702",
  ]);

  set_light(1);
}
