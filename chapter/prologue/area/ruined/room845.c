inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Scorched Pass";
  long_desc = "Scorched boards lie half-buried in damp dust, the passage silent and ruined. A low sill and slumped counter are soft with rot and mildew, hinting at a trade stall left to waste.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room846", "east",
    "chapter/prologue/area/ruined/room146", "north",
  });
}
