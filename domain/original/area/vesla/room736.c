inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Market Lot";
  long_desc = "Low foundations ring a vacant patch, silent beneath dust, mildew, and rot. A\n"
        + "broken sign frame hints at trade, the lot dilapidated and in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room173", "west",
  });
}

