inherit "room/room";

void create() {
  ::create();

  short_desc = "West Crossing";
  long_desc =
    "The intersection is marked by a low stone post worn smooth. Thin grass pushes\n"
    "up through the central joints.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room261", "west",
    "domain/original/area/anshelm/room259", "east",
    "domain/original/area/anshelm/room264", "north",
  });

  set_light(1);
}
