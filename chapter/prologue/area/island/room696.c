inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "North Corridor";
  long_desc = "North Corridor.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room693",
    "north" : "/chapter/prologue/area/island/room697",
  ]);

  set_light(1);
}
