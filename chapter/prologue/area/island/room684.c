inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Hallway";
  long_desc = "Hallway.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room685",
    "north" : "/chapter/prologue/area/island/room679",
  ]);

  set_light(1);
}
