inherit "room/room";

void create() {
  ::create();


  short_desc = "Council Chamber";
  long_desc = "Council Chamber.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room681",
    "west" : "/domain/original/area/island/room683",
  ]);

  set_light(1);
}
