inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Bend";
  long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room38", "north",
    "chapter/prologue/area/sunken/room36", "south",
  });

  set_light(1);
}
