inherit "room/room";

void create() {
  ::create();


  short_desc = "Central Chamber";
  long_desc = "Central Chamber.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room715",
    "west" : "/domain/original/area/island/room713",
  ]);

  set_light(1);
}
