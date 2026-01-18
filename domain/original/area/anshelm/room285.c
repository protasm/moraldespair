inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward a wider street, its stones chipped and uneven. A sagging\n"
    "lintel hangs over a dark doorway.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room284", "west",
  });
}
