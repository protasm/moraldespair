inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Hearth";
  long_desc = "Soot-dark stone surrounds a dead hearth, its ash long blown away. Crumbling brick and damp stains mark the still chamber.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room224",
    "north":"/chapter/prologue/area/ruined/room122",
  ]);

  set_light(1);
}
