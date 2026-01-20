inherit "room/room";

void create() {
  ::create();


  short_desc = "Keep Of Alcibiades";
  long_desc = "Keep Of Alcibiades.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room659",
    "east" : "/domain/original/area/island/room658",
    "north" : "/domain/original/area/island/room640",
  ]);

  set_light(1);
}
