inherit "room/room";

void create() {
  ::create();

  short_desc = "Leaning Way";
  long_desc = "Two aligned walls hint at a corridor now filled with drifted sand. Loose stones shift with each step, exposing darker layers below.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room53", "east",
    "chapter/prologue/area/sunken/room51", "west",
  });

  set_light(1);
}
