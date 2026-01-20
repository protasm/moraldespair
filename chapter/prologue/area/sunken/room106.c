inherit "room/room";

void create() {
  ::create();

  short_desc = "Scarred Hollow";
  long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window frames stare out, their ledges buried in dust.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room104", "west",
    "chapter/prologue/area/sunken/room1126", "up",
  });

  set_light(1);
}
