inherit "room/room";

void create() {
  ::create();

  short_desc = "Worn Way";
  long_desc = "Wind funnels along the empty way, lifting grit across pale weathered basalt. Collapsed beams rest against a wall, leaving the road half blocked in places.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room196", "east",
    "chapter/prologue/area/ruined/room194", "west",
  });

  set_light(1);
}

