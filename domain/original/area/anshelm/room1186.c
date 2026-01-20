inherit "room/room";

void create() {
  ::create();

  short_desc = "Arcade Row";
  long_desc =
    "Shallow arcades line the street, their arches chipped and stained. Bits of\n"
    "colored tile still cling to the lower walls.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1185", "west",
    "domain/original/area/anshelm/room1187", "east",
    "domain/original/area/anshelm/room1190", "north",
  });

  set_light(1);
}
