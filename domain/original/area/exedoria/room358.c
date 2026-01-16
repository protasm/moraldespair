inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Hall Bend";
  long_desc = "The hallway bends around a thick pillar, hiding what lies beyond. Dust gathers\nin the corner where the light fades.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room359", "west",
    "domain/original/area/exedoria/room357", "north",
  });
}
