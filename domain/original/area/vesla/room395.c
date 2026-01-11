inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Turner's Bench";
  long_desc = "A cracked lathe stands in the corner, silent and dilapidated beneath dust and\n"
        + "mildew. Spilled shavings and dulled tools sit in rot, hinting at careful\n"
        + "turning left in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room209", "south",
  });
}

