inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Leaning Way";
  long_desc = "Two aligned walls hint at a corridor now filled with drifted sand. Loose stones shift with each step, exposing darker layers below.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room20", "north",
    "chapter/prologue/area/sunken/room22", "south",
  });

  set_light(1);
}
