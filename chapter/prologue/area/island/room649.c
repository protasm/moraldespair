inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Dwarven Home";
  long_desc = "Dwarven Home.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room648",
  ]);

  set_light(1);
}
