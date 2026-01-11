inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Grate Shed";
  long_desc = "A low shed sags over a grated stone lip, its boards soft with rot. Mildew and\n"
              + "silt stain the edges, hinting at a passage once kept clear below.\n";
  dest_dir = ({
    "domain/original/area/vesla/room792", "south",
  });
}
