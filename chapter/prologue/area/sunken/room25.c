inherit "/room/room";

void create() {
  ::create();

  short_desc = "Scarred Hollow";
  long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window frames stare out, their ledges buried in dust.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room24", "east",
    "chapter/prologue/area/sunken/room26", "west",
  });

  set_light(1);
}
