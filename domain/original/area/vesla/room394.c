inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Smoke";
  long_desc = "Soot clings to the stone, and rusted hooks hang in a silence of dust and\n"
        + "mildew. Rotting tubs and ash-stained gutters hint at preserved fare in\n"
        + "dilapidated disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room210", "south",
  });
}

