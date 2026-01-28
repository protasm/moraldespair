inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Barrack Crossing";
  long_desc =
    "Two roads meet before a line of long, low buildings. Their doorways gape, dark\n"
    "and silent.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room266",
    "west" : "/chapter/prologue/area/refuge/room268",
    "east" : "/chapter/prologue/area/refuge/room276",
    "north" : "/chapter/prologue/area/refuge/room273",
  ]);

  set_light(1);
}
