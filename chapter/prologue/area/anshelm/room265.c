inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Gate";
  long_desc =
    "A high arch leads toward the inner rise of the city. The guard slots are\n"
    "empty, their stone edges crumbled.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room264",
    "west" : "/chapter/prologue/area/anshelm/room282",
    "east" : "/chapter/prologue/area/anshelm/room1198",
    "north" : "/chapter/prologue/area/anshelm/room266",
  ]);

  set_light(1);
}
