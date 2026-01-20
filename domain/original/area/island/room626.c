inherit "room/room";

void create() {
  ::create();


  short_desc = "Ruins";
  long_desc = "Ruins.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room627",
    "west" : "/domain/original/area/island/room606",
  ]);

  set_light(1);
}
