inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Dry Tap";
  long_desc = "A cracked counter and dry cask stand in silence, the space dilapidated and\n"
        + "dim. Dust, mildew, and rot cling to the shelves, hinting at a taproom left in\n"
        + "disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room850", "west",
  });
}

