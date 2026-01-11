inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Scorched Pass";
  long_desc = "Scorched boards lie half-buried in damp dust, the passage silent and\n"
        + "dilapidated. A low sill and slumped counter are soft with rot and mildew,\n"
        + "hinting at a trade stall in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room846", "east",
    "domain/original/area/vesla/room146", "north",
  });
}

