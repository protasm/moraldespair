inherit "room/room";

void create() {
  ::create();

  short_desc = "Rose Altar";
  long_desc =
    "A small altar of stone stands against the wall, its carvings softened. Dried\n"
    "petals lie scattered in the dust.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/anshelm/room1330",
  ]);

  set_light(1);
}
