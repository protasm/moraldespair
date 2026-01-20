inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Office";
  long_desc = "A square office holds a heavy desk and a cracked seal. The walls bear faint\nmarks of old banners.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room920", "south",
  });
}
