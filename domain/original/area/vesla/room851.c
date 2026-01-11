inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Quiet Bunks";
  long_desc = "Rough bunks sag against the walls, silent in dust, rot, and mildew. Hooks and\n"
        + "pegs hang over a dilapidated floor, hinting at lodging left in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room850", "south",
  });
}

