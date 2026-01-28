inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Broken Rotunda";
  long_desc = "A circular chamber rises around a cracked dome. Light spills through gaps\nwhere the roof has fallen.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room376",
  ]);

  set_light(1);
}
