inherit "/room/room";

void create() {
  ::create();

  short_desc = "Dusty Stretch";
  long_desc = "The path angles around a heap of fallen blocks, forcing a slow turn. Hollow window frames stare out, their ledges buried in dust. The wind slides through with a dry hiss.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room64", "north",
    "chapter/prologue/area/sunken/room66", "south",
    "chapter/prologue/area/sunken/room1015", "east",
    "chapter/prologue/area/sunken/room430", "west",
  });

  set_light(1);
}
