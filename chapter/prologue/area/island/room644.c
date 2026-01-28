inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Highland Avenue";
  long_desc = "Highland Avenue.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room643",
    "west" : "/chapter/prologue/area/island/room646",
    "east" : "/chapter/prologue/area/island/room648",
    "north" : "/chapter/prologue/area/island/room645",
  ]);

  set_light(1);
}
