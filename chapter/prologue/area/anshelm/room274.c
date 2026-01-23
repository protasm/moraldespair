inherit "room/room";

void create() {
  ::create();

  short_desc = "Town Arch";
  long_desc =
    "The town gate's stone throat opens above, its portcullis long vanished. Rain\n"
    "has carved dark trails down the blocks.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room273",
    "north" : "/chapter/prologue/area/anshelm/room275",
  ]);

  set_light(1);
}
