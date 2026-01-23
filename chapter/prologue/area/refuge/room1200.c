inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Works";
  long_desc =
    "An unfinished structure lies open to the weather, its walls buckled. Bundles\n"
    "of warped timber rot along the edges.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room276",
  ]);

  set_light(1);
}
