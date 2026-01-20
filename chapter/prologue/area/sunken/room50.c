inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Bend";
  long_desc = "Broken steps climb to a terrace of shattered stone, then fall away. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room49", "south",
    "chapter/prologue/area/sunken/room51", "east",
  });

  set_light(1);
}
