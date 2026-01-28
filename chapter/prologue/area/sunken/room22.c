inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Eroded Rise";
  long_desc = "A jagged seam in the paving marks the line of a sunken run. Ash and grit collect in corners, damped by occasional trickles.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room21", "north",
    "chapter/prologue/area/sunken/room23", "west",
  });

  set_light(1);
}
