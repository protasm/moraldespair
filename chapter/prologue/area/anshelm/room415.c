inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Salon";
  long_desc =
    "A wide room holds a chipped dance floor and a sagging balcony. Dust coats the\n"
    "rail where hands once rested.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room240", "east",
    "chapter/prologue/area/anshelm/room414", "south",
  });

  set_light(1);
}
