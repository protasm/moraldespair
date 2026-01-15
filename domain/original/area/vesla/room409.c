inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Nailed Notices";
  long_desc = "A warped board is riddled with rusted nails, silent under dust and mildew.\n"
              + "Faded names and tally marks sit in rot, hinting at claims once posted in a\n"
              + "long-quiet hall.\n";
  dest_dir = ({
    "domain/original/area/vesla/room219", "east",
  });
}
