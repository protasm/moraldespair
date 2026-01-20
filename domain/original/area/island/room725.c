inherit "room/room";

void create() {
  ::create();


  short_desc = "Bazaar Crossroad";
  long_desc = "Bazaar Crossroad.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room726",
    "east" : "/domain/original/area/island/room729",
    "north" : "/domain/original/area/island/room724",
  ]);

  set_light(1);
}
