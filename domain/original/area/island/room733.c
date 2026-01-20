inherit "room/room";

void create() {
  ::create();


  short_desc = "Administrative hallway";
  long_desc = "Administrative hallway.\n";
  dest_dir = ([
    "north" : "/domain/original/area/island/room732",
  ]);

  set_light(1);
}
