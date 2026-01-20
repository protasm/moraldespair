inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple Shop";
  long_desc = "Temple Shop.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room672",
    "south" : "/domain/original/area/island/room663",
  ]);

  set_light(1);
}
