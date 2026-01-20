inherit "room/room";

void create() {
  ::create();


  short_desc = "Armoury";
  long_desc = "Armoury.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room631",
    "west" : "/domain/original/area/island/room633",
  ]);

  set_light(1);
}
