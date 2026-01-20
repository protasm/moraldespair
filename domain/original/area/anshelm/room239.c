inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Crossing";
  long_desc =
    "Two streets meet in a small square of cracked paving. An empty fountain base\n"
    "sits crooked against the curb.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room238", "south",
    "domain/original/area/anshelm/room414", "west",
    "domain/original/area/anshelm/room1185", "east",
    "domain/original/area/anshelm/room240", "north",
  });

  set_light(1);
}
