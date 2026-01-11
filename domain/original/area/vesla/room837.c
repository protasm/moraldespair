inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stalled Row";
  long_desc = "Rotted awnings sag over empty stalls, their poles splintered and gray. Scales\n"
              + "and shallow trays lie scattered in dust, and mildew darkens the stone where\n"
              + "trade once clustered.\n";
  dest_dir = ({
    "domain/original/area/vesla/room422", "west",
  });
}
