inherit "room/room";

void create() {
  ::create();


  short_desc = "South End of Highland Avenue";
  long_desc = "South End of Highland Avenue.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room638",
    "west" : "/domain/original/area/island/room640",
  ]);

  set_light(1);
}
