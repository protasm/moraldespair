inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Way";
  long_desc = "The paving breaks into small islands, the gaps filled with dark soil and rot.\n"
              + "The street narrows toward a wider crossing ahead, where the stones dip\n"
              + "slightly.\n";
  dest_dir = ({
    "domain/original/area/vesla/room197", "east",
    "domain/original/area/vesla/room195", "west",
  });
}

