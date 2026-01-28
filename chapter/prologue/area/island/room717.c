inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Poison Shop";
  long_desc = "Poison Shop.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room635",
  ]);

  set_light(1);
}
