inherit "room/room";

void create() {
  ::create();


  short_desc = "Gate House";
  long_desc = "Gate House.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room676",
    "west" : "/domain/original/area/island/room614",
    "east" : "/domain/original/area/island/room693",
    "north" : "/domain/original/area/island/room686",
  ]);

  set_light(1);
}
