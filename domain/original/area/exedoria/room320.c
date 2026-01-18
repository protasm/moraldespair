inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Round Door";
  long_desc = "A heavy round door stands in a curved wall, swollen and cracked by time. Moss\ngathers in the seams where the frame once fit tight.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room315", "north",
  });
}
