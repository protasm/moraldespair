inherit "room/room";

void create() {
  ::create();


  short_desc = "Crowded Thoroughfare";
  long_desc = "Crowded Thoroughfare.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room724",
    "north" : "/domain/original/area/island/room637",
  ]);

  set_light(1);
}
