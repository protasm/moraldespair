inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Railed Gate";
  long_desc = "A short railing borders a narrow entry in the wall. The iron bars are bent and\nmottled with rust.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room336", "south",
  });
}
