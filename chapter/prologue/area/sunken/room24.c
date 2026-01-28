inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Faded Corridor";
  long_desc = "A shallow slope of debris leads down into a widened passage. Fire-blackened patches run along the base of the walls.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room23", "east",
    "chapter/prologue/area/sunken/room25", "west",
  });

  set_light(1);
}
