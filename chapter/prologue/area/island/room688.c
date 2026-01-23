inherit "room/room";

void create() {
  ::create();


  short_desc = "Rhian's Potion Shop";
  long_desc = "Rhian's Potion Shop.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room615",
  ]);

  set_light(1);
}
