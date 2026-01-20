inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Gate";
  long_desc =
    "A high arch leads toward the inner rise of the city. The guard slots are\n"
    "empty, their stone edges crumbled.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room264", "south",
    "chapter/prologue/area/anshelm/room282", "west",
    "chapter/prologue/area/anshelm/room1198", "east",
    "chapter/prologue/area/anshelm/room266", "north",
  });

  set_light(1);
}
