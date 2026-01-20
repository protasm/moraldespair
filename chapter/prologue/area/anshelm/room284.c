inherit "room/room";

void create() {
  ::create();

  short_desc = "Brick Lane";
  long_desc =
    "The lane is edged by low brickwork and crumbling steps. A faded tile pattern\n"
    "lingers in the dust.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room283", "west",
    "chapter/prologue/area/anshelm/room285", "east",
    "chapter/prologue/area/anshelm/room1327", "north",
  });

  set_light(1);
}
