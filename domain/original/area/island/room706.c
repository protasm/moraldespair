inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room704",
    "south" : "/domain/original/area/island/room710",
    "north" : "/domain/original/area/island/room707",
  ]);

  set_light(1);
}
