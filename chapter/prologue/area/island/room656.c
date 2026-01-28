inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Dwarven Home";
  long_desc = "Dwarven Home.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room653",
  ]);

  set_light(1);
}
