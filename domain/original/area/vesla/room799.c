inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Wet Cut";
  long_desc = "Moisture beads on the close walls, and the paving is dark with mildew. A rusted hinge stump and scored stone hint at a narrow door once kept shut.";
  dest_dir = ({
    "domain/original/area/vesla/room802", "west",
    "domain/original/area/vesla/room800", "east",
    "domain/original/area/vesla/room798", "south",
  });
}
