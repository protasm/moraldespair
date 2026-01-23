inherit "room/room";

void create() {
  ::create();


  short_desc = "Bedchamber";
  long_desc = "Bedchamber.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room701",
    "west" : "/chapter/prologue/area/island/room699",
  ]);

  set_light(1);
}
