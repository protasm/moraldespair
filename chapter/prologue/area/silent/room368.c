inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Empty Hall";
  long_desc = "A grand hall stands stripped to bare stone, banners long gone. Ash marks a\nhearth that has not burned in years.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room288",
  ]);

  set_light(1);
}
