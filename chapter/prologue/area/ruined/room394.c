inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Smoke";
  long_desc = "Soot clings to the stone, and rusted hooks hang in a silence of dust and mildew. Rotting tubs and ash-stained gutters hint at preserved fare in long-neglected ruin.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room210", "south",
  });
}
