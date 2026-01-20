inherit "room/room";

void create() {
  ::create();

  short_desc = "East Post";
  long_desc =
    "A guard niche watches the road through a broken arrow slit. The ledge is slick\n"
    "with damp and moss.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room237", "northwest",
    "domain/original/area/anshelm/room1155", "east",
  });

  set_light(1);
}
