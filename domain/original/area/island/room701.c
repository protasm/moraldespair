inherit "room/room";

void create() {
  ::create();


  short_desc = "Entryway";
  long_desc = "Entryway.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room700",
    "south" : "/domain/original/area/island/room702",
  ]);

  set_light(1);
}
