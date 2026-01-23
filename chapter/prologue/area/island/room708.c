inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room702",
    "south" : "/chapter/prologue/area/island/room707",
    "north" : "/chapter/prologue/area/island/room709",
  ]);

  set_light(1);
}
