inherit "room/room";

void create() {
  ::create();

  short_desc = "Barrack Crossing";
  long_desc =
    "Two roads meet before a line of long, low buildings. Their doorways gape, dark\n"
    "and silent.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room266", "south",
    "chapter/prologue/area/anshelm/room268", "west",
    "chapter/prologue/area/anshelm/room276", "east",
    "chapter/prologue/area/anshelm/room273", "north",
  });

  set_light(1);
}
