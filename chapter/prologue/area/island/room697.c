inherit "room/room";

void create() {
  ::create();


  short_desc = "Guard Room";
  long_desc = "Guard Room.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room698",
    "south" : "/chapter/prologue/area/island/room696",
  ]);

  set_light(1);
}
