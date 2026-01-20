inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple Plaza";
  long_desc = "Temple Plaza.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room715",
    "east" : "/domain/original/area/island/room671",
    "south" : "/domain/original/area/island/room662",
  ]);

  set_light(1);
}
