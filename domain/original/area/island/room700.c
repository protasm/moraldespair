inherit "room/room";

void create() {
  ::create();


  short_desc = "Bedchamber";
  long_desc = "Bedchamber.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room701",
    "west" : "/domain/original/area/island/room699",
  ]);

  set_light(1);
}
