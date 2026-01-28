inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room652",
    "south" : "/chapter/prologue/area/island/room648",
  ]);

  set_light(1);
}
