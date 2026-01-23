inherit "room/room";

void create() {
  ::create();


  short_desc = "West Harem";
  long_desc = "West Harem.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room699",
    "west" : "/chapter/prologue/area/island/room697",
  ]);

  set_light(1);
}
