inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ash-Streaked Crossing";
  long_desc = "A narrow lane bends between broken walls, the ground uneven and gritty. Char marks stripe the walls, and fine ash mixes with grit underfoot.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room93", "down",
  });

  set_light(1);
}
