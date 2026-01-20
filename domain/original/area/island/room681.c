inherit "room/room";

void create() {
  ::create();


  short_desc = "Audience Hall";
  long_desc = "Audience Hall.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room682",
    "south" : "/domain/original/area/island/room680",
  ]);

  set_light(1);
}
