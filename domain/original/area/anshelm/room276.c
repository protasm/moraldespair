inherit "room/room";

void create() {
  ::create();

  short_desc = "Barrack Way";
  long_desc =
    "The street is lined with long foundations and collapsed roofs. Rusted iron\n"
    "hoops lie in the dirt.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room267", "west",
    "domain/original/area/anshelm/room277", "east",
    "domain/original/area/anshelm/room1200", "north",
  });

  set_light(1);
}
