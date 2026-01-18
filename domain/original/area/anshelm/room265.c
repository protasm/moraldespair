inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Upper Gate";
  long_desc =
    "A high arch leads toward the inner rise of the city. The guard slots are\n"
    "empty, their stone edges crumbled.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room264", "south",
    "domain/original/area/anshelm/room282", "west",
    "domain/original/area/anshelm/room1198", "east",
    "domain/original/area/anshelm/room266", "north",
  });
}
