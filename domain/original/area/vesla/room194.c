inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Worn Way";
  long_desc = "The street straightens here, hemmed by sagging fronts and shutterless frames. A line of rust runs along the gutter, and thin weeds take the joints slowly.";
  dest_dir = ({
    "domain/original/area/vesla/room195", "east",
    "domain/original/area/vesla/room193", "west",
  });
}

