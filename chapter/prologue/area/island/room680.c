inherit "room/room";

void create() {
  ::create();


  short_desc = "Hallway";
  long_desc = "Hallway.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room679",
    "north" : "/chapter/prologue/area/island/room681",
  ]);

  set_light(1);
}
