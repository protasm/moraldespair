inherit "room/room";

void create() {
  ::create();


  short_desc = "East Harem";
  long_desc = "East Harem.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room700",
    "west" : "/chapter/prologue/area/island/room698",
  ]);

  set_light(1);
}
