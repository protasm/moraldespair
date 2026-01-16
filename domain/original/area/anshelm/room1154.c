inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Post";
  long_desc =
    "A guard niche watches the road through a broken arrow slit. The ledge is slick\n"
    "with damp and moss.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room237", "northwest",
    "domain/original/area/anshelm/room1155", "east",
  });
}
