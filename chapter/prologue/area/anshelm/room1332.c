inherit "room/room";

void create() {
  ::create();

  short_desc = "South Statuary";
  long_desc =
    "Broken statues lean against the south wall, their faces worn blank. Fragments\n"
    "of marble litter the floor.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/anshelm/room1330",
  ]);

  set_light(1);
}
