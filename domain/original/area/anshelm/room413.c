inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Club";
  long_desc =
    "A small hall opens here with a low stage and a cracked rail. Tattered curtains\n"
    "hang in strips along the back wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room238", "east",
    "domain/original/area/anshelm/room414", "north",
  });
}
