inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Town Arch";
  long_desc =
    "The town gate's stone throat opens above, its portcullis long vanished. Rain\n"
    "has carved dark trails down the blocks.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room273", "south",
    "domain/original/area/anshelm/room275", "north",
  });
}
