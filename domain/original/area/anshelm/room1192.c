inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Caved Chamber";
  long_desc =
    "A heavy collapse has split this chamber, exposing the sky. Slabs of stone lie\n"
    "piled in the center.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room240", "west",
  });
}
