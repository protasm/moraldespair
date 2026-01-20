inherit "room/room";

void create() {
  ::create();

  short_desc = "Sentry Street";
  long_desc =
    "The street is broader here, with a strip of packed earth between stones. A\n"
    "toppled post leans against a wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room268", "east",
    "chapter/prologue/area/anshelm/room270", "west",
  });

  set_light(1);
}
