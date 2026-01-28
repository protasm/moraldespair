inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "South Entryway";
  long_desc = "South Entryway.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room704",
  ]);

  set_light(1);
}
