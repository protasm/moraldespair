inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);
  short_desc = "Cold Hearth";
  long_desc = "Soot-dark stone surrounds a dead hearth, its ash long blown away. Crumbling brick and damp stains mark the still chamber.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room224", "east",
    "chapter/prologue/area/ruined/room122", "north",
  });
}
