inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Bridge";
  long_desc = "A heavy bridge spans a shallow moat now filled with reed and mud. Chains hang\nslack where the lift once rose.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room310", "east",
    "domain/original/area/exedoria/room356", "west",
  });
}
