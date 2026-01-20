inherit "room/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room643",
    "south" : "/domain/original/area/island/room641",
  ]);

  set_light(1);
}
