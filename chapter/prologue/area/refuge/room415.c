inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Salon";
  long_desc =
    "A wide room holds a chipped dance floor and a sagging balcony. Dust coats the\n"
    "rail where hands once rested.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room240",
    "south" : "/chapter/prologue/area/refuge/room414",
  ]);

  set_light(1);
}
