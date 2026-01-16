inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "High Room";
  long_desc = "A small room opens onto a broken balcony above the ground. The ceiling is\nstained with rain.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room909", "down",
  });
}
