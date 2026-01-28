inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room703",
    "east" : "/chapter/prologue/area/island/room708",
    "north" : "/chapter/prologue/area/island/room701",
  ]);

  set_light(1);
}
