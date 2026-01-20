inherit "room/room";

void create() {
  ::create();


  short_desc = "Entryway";
  long_desc = "Entryway.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room677",
    "south" : "/domain/original/area/island/room694",
    "north" : "/domain/original/area/island/room696",
  ]);

  set_light(1);
}
