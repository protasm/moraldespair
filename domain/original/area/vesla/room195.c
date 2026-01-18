inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Way";
  long_desc = "Wind funnels along the empty way, lifting grit across pale weathered basalt. Collapsed beams rest against a wall, leaving the road half blocked in places.";
  dest_dir = ({
    "domain/original/area/vesla/room196", "east",
    "domain/original/area/vesla/room194", "west",
  });
}

