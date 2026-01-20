inherit "room/room";

void create() {
  ::create();

  short_desc = "Shuttered Street";
  long_desc =
    "Tall shutters hang open or lie broken along the street. A few carved lintels\n"
    "remain, softened by weather.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1188", "east",
    "domain/original/area/anshelm/room1186", "west",
  });

  set_light(1);
}
