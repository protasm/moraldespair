inherit "room/room";

void create() {
  ::create();


  short_desc = "North Corridor";
  long_desc = "North Corridor.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room693",
    "north" : "/domain/original/area/island/room697",
  ]);

  set_light(1);
}
