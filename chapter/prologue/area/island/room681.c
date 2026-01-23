inherit "room/room";

void create() {
  ::create();


  short_desc = "Audience Hall";
  long_desc = "Audience Hall.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room682",
    "south" : "/chapter/prologue/area/island/room680",
  ]);

  set_light(1);
}
