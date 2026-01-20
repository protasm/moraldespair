inherit "room/room";

void create() {
  ::create();


  short_desc = "Gate House";
  long_desc = "Gate House.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room614",
    "west" : "/domain/original/area/island/room679",
  ]);

  set_light(1);
}
