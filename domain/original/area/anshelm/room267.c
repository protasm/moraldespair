inherit "room/room";

void create() {
  ::create();

  short_desc = "Barrack Crossing";
  long_desc =
    "Two roads meet before a line of long, low buildings. Their doorways gape, dark\n"
    "and silent.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room266", "south",
    "domain/original/area/anshelm/room268", "west",
    "domain/original/area/anshelm/room276", "east",
    "domain/original/area/anshelm/room273", "north",
  });

  set_light(1);
}
