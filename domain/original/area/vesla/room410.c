inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Cut";
  long_desc =
    "A tight passage runs between leaning walls, choked with damp rot and black\n"
    "mildew. Broken drains and sagging lintels suggest a service way once kept\n"
    "clear, now sealed in silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room411", "west",
    "domain/original/area/vesla/room122", "south",
    "domain/original/area/vesla/room792", "north",
  });
}
