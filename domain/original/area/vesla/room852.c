inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Dry Tap";
  long_desc = "A cracked counter and dry cask stand in silence, the space dim and neglected.\n"
              + "Dust, mildew, and rot cling to the shelves, hinting at a taproom left to fade.\n";
  dest_dir = ({
    "domain/original/area/vesla/room850", "west",
  });
}
