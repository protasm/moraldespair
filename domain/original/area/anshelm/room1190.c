inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Taproom";
  long_desc =
    "A low room opens onto the street, its counter broken and bare. Stained glass\n"
    "fragments glimmer in the dust.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1191", "west",
    "domain/original/area/anshelm/room1186", "south",
  });
}
