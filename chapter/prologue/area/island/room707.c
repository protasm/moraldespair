inherit "room/room";

void create() {
  ::create();


  short_desc = "Turkish Bath";
  long_desc = "Turkish Bath.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room703",
    "south" : "/chapter/prologue/area/island/room706",
    "north" : "/chapter/prologue/area/island/room708",
  ]);

  set_light(1);
}
