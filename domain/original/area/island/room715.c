inherit "room/room";

void create() {
  ::create();


  short_desc = "Eastern Chamber";
  long_desc = "Eastern Chamber.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room672",
    "west" : "/domain/original/area/island/room714",
  ]);

  set_light(1);
}
