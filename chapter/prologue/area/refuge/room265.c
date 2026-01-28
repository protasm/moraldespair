inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Upper Gate";
  long_desc =
    "A high arch leads toward the inner rise of the city. The guard slots are\n"
    "empty, their stone edges crumbled.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room264",
    "west" : "/chapter/prologue/area/refuge/room282",
    "east" : "/chapter/prologue/area/refuge/room1198",
    "north" : "/chapter/prologue/area/refuge/room266",
  ]);

  set_light(1);
}
