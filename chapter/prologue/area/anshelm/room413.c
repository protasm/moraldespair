inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Club";
  long_desc =
    "A small hall opens here with a low stage and a cracked rail. Tattered curtains\n"
    "hang in strips along the back wall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room238",
    "north" : "/chapter/prologue/area/anshelm/room414",
  ]);

  set_light(1);
}
