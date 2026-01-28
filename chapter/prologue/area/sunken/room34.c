inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dusty Stretch";
  long_desc = "The path angles around a heap of fallen blocks, forcing a slow turn. Hollow window frames stare out, their ledges buried in dust. The wind slides through with a dry hiss.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room33", "east",
    "chapter/prologue/area/sunken/room35", "west",
  });

  set_light(1);
}
