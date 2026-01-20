inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room702",
    "south" : "/domain/original/area/island/room707",
    "north" : "/domain/original/area/island/room709",
  ]);

  set_light(1);
}
