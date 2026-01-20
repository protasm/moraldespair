inherit "room/room";

void create() {
  ::create();


  short_desc = "Power System Generator";
  long_desc = "Power System Generator.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room692",
    "west" : "/domain/original/area/island/room618",
  ]);

  set_light(1);
}
