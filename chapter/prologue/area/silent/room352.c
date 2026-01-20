inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Paneled Hall";
  long_desc = "Wood panels line the hall, warped and split by damp. Their varnish has dulled\nto a gray sheen.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room351", "west",
    "chapter/prologue/area/silent/room353", "north",
  });
}
