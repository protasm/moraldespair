inherit "room/room";

void create() {
  ::create();

  short_desc = "East Lane";
  long_desc =
    "The lane opens toward a wider street, its stones chipped and uneven. A sagging\n"
    "lintel hangs over a dark doorway.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room284", "west",
  });

  set_light(1);
}
