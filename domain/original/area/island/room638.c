inherit "room/room";

void create() {
  ::create();


  short_desc = "Tunnel Under Canal";
  long_desc = "Tunnel Under Canal.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room637",
    "west" : "/domain/original/area/island/room639",
  ]);

  set_light(1);
}
