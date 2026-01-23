inherit "room/room";

void create() {
  ::create();


  short_desc = "Hermit's Chamber";
  long_desc = "Hermit's Chamber.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room655",
  ]);

  set_light(1);
}
