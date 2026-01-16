inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Chamber";
  long_desc = "This chamber holds a chill that lingers year round. Frost clings to the stone\nin thin, pale sheets.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room346", "west",
  });
}
