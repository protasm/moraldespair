inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Salon";
  long_desc =
    "A wide room holds a chipped dance floor and a sagging balcony. Dust coats the\n"
    "rail where hands once rested.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room240", "east",
    "domain/original/area/anshelm/room414", "south",
  });
}
