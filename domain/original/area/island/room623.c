inherit "room/room";

void create() {
  ::create();


  short_desc = "Western Part of Beach";
  long_desc = "Western Part of Beach.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room606",
    "west" : "/domain/original/area/island/room624",
  ]);

  set_light(1);
}
