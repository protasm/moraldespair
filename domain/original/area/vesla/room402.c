inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Still";
  long_desc = "A copper coil lies split on the floor, silent and dilapidated under dust and\n"
        + "mildew. Dry barrels and a stained hearth sit in rot, hinting at spirits once\n"
        + "made here in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room216", "east",
  });
}

