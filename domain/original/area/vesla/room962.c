inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Shuttered Front";
  long_desc = "A warped counter blocks the entry, silent under dust and mildew. Bare shelves\n"
              + "and a torn awning sit in rot, hinting at trade long faded.\n";
  dest_dir = ({
    "domain/original/area/vesla/room199", "west",
  });
}
