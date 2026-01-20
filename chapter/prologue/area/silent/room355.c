inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Bridge";
  long_desc = "A heavy bridge spans a shallow moat now filled with reed and mud. Chains hang\nslack where the lift once rose.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room310", "east",
    "chapter/prologue/area/silent/room356", "west",
  });
}
