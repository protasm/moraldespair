inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Wax Alcove";
  long_desc = "A side chamber is lined with niche shelves, now empty and gray with dust. Wax drips have hardened on the floor, their puddles greened by mildew and tracked with grit from a door that no longer shuts.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room405", "south",
  });
}
