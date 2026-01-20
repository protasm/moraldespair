inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Shuttered Front";
  long_desc = "A warped counter blocks the entry, silent under dust and mildew. Bare shelves and a torn awning sit in rot, hinting at trade long faded.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room199", "west",
  });
}
