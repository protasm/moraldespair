inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Office";
  long_desc = "A square office holds a heavy desk and a cracked seal. The walls bear faint\nmarks of old banners.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room920",
  ]);

  set_light(1);
}
