inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sentry Street";
  long_desc =
    "The street is broader here, with a strip of packed earth between stones. A\n"
    "toppled post leans against a wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room268", "east",
    "domain/original/area/anshelm/room270", "west",
  });
}
