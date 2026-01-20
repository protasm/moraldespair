inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Workroom";
  long_desc = "Long tables and rusted tools line the walls. A few cracked vessels still rest\non their shelves.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room904", "east",
  });
}
