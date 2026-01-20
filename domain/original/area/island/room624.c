inherit "room/room";

void create() {
  ::create();


  short_desc = "East of the waterfall";
  long_desc = "East of the waterfall.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room623",
    "west" : "/domain/original/area/island/room625",
  ]);

  set_light(1);
}
