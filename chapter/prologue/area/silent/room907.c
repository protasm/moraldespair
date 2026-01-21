inherit "room/room";

void create() {
  ::create();

  short_desc = "Gravel Path";
  long_desc = "A gravel path winds between scrub and low stone walls. Small stones shift with\nany movement.\n";
  dest_dir = ([
    "northwest":"/chapter/prologue/area/silent/room908",
    "southwest":"/chapter/prologue/area/silent/room604",
  ]);

  set_light(1);
}
