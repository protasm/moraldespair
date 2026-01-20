inherit "room/room";

void create() {
  ::create();


  short_desc = "Hallway";
  long_desc = "Hallway.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room685",
    "north" : "/domain/original/area/island/room679",
  ]);

  set_light(1);
}
