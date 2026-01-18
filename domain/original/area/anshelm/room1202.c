inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Abandoned Works";
  long_desc =
    "Loose courses of stone mark the outline of a forgotten build. Wind has piled\n"
    "grit against a fallen beam.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room273", "southeast",
  });
}
