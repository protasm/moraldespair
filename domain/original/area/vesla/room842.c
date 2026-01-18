inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Charred Lane";
  long_desc = "Fire-split timbers jut from the stonework, soft with mildew and long silent in ruin. Dust coats the old thresholds, and rot gnaws at doorframes that hint at narrow rooms now fallen and empty.";
  dest_dir = ({
    "domain/original/area/vesla/room146", "south",
    "domain/original/area/vesla/room841", "east",
    "domain/original/area/vesla/room844", "north",
  });
}
