inherit "room/room";

void create() {
  ::create();


  short_desc = "Trophy Room";
  long_desc = "Trophy Room.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room682",
  ]);

  set_light(1);
}
