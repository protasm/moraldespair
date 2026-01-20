inherit "room/room";

void create() {
  ::create();


  short_desc = "West Harem";
  long_desc = "West Harem.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room699",
    "west" : "/domain/original/area/island/room697",
  ]);

  set_light(1);
}
