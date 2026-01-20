inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cold Still";
  long_desc = "A copper coil lies split on the floor, silent and wrecked under dust and mildew. Dry barrels and a stained hearth sit in rot, hinting at spirits once made here and long forgotten.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room216", "east",
  });
}
