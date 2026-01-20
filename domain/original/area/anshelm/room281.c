inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Row";
  long_desc =
    "The lane is straight and silent, edged by worn thresholds. A chipped well cap\n"
    "sits off to one side.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room258", "west",
    "domain/original/area/anshelm/room1328", "east",
    "domain/original/area/anshelm/room1197", "north",
  });

  set_light(1);
}
