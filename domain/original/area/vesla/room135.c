inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "Basalt paving runs between dark stone walls, the joints split by weeds and\n"
              + "grit. A low drift of broken tile lies where slow runoff has carved shallow\n"
              + "channels.\n";
  dest_dir = ({
    "domain/original/area/vesla/room136", "south",
    "domain/original/area/vesla/room133", "north",
  });
}
