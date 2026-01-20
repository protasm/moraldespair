inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Avenue";
  long_desc =
    "A wide street runs between elegant facades, their arches chipped and open.\n"
    "Wrought iron balconies sag above the broken paving.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1157", "west",
    "domain/original/area/anshelm/room1147", "east",
    "domain/original/area/anshelm/room1168", "south",
  });

  set_light(1);
}
