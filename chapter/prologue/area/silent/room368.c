inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Hall";
  long_desc = "A grand hall stands stripped to bare stone, banners long gone. Ash marks a\nhearth that has not burned in years.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room288", "north",
  });
}
