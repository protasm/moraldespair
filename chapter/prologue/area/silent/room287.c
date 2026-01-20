inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Deep ruts crease the old street, packed with silt and stray grass. Collapsed\ncurbs and leaning posts hint at buildings beyond the weeds.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room286", "west",
    "chapter/prologue/area/silent/room288", "east",
    "chapter/prologue/area/silent/room330", "south",
  });
}
