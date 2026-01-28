inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Soylent Green";
  long_desc = "Soylent Green.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room613",
  ]);

  set_light(1);
}
