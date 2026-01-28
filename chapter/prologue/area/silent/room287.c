inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Deep ruts crease the old street, packed with silt and stray grass. Collapsed\ncurbs and leaning posts hint at buildings beyond the weeds.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room286",
    "east":"/chapter/prologue/area/silent/room288",
    "south":"/chapter/prologue/area/silent/room330",
  ]);

  set_light(1);
}
