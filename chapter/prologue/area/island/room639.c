inherit "room/room";

void create() {
  ::create();


  short_desc = "South End of Highland Avenue";
  long_desc = "South End of Highland Avenue.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room638",
    "west" : "/chapter/prologue/area/island/room640",
  ]);

  set_light(1);
}
