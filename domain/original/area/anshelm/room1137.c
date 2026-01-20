inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Landing";
  long_desc =
    "The landing opens onto two dark passages with flaked plaster. A fallen torch\n"
    "bracket lies on the floor.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1136", "down",
    "domain/original/area/anshelm/room1142", "east",
    "domain/original/area/anshelm/room1138", "up",
  });

  set_light(1);
}
