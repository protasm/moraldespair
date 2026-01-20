inherit "room/room";

void create() {
  ::create();


  short_desc = "Foyer";
  long_desc = "Foyer.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room684",
    "east" : "/domain/original/area/island/room678",
    "north" : "/domain/original/area/island/room680",
  ]);

  set_light(1);
}
