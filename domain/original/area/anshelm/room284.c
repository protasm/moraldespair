inherit "room/room";

void create() {
  ::create();

  short_desc = "Brick Lane";
  long_desc =
    "The lane is edged by low brickwork and crumbling steps. A faded tile pattern\n"
    "lingers in the dust.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room283", "west",
    "domain/original/area/anshelm/room285", "east",
    "domain/original/area/anshelm/room1327", "north",
  });

  set_light(1);
}
