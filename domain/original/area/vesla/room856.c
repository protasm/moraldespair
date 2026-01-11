inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Shaving Shed";
  long_desc = "The floor is buried in old shavings turned to pulp, silent and dilapidated.\n"
        + "Dulled chisels and a chipped mallet lie in dust, mildew, and rot, hinting at\n"
        + "carved work in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room138", "east",
  });
}

