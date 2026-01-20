inherit "room/room";

void create() {
  ::create();

  short_desc = "Soldier Row";
  long_desc =
    "The buildings here are little more than low walls. Grass grows thick where\n"
    "floors once lay.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room278", "east",
    "domain/original/area/anshelm/room276", "west",
  });

  set_light(1);
}
