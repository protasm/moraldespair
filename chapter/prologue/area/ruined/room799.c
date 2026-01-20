inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Wet Cut";
  long_desc = "Moisture beads on the close walls, and the paving is dark with mildew. A rusted hinge stump and scored stone hint at a narrow door once kept shut.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room802", "west",
    "chapter/prologue/area/ruined/room800", "east",
    "chapter/prologue/area/ruined/room798", "south",
  });
}
