inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Corridor";
  long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room91", "east",
    "chapter/prologue/area/sunken/room1132", "up",
  });

  set_light(1);
}
