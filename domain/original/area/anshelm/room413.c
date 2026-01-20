inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Club";
  long_desc =
    "A small hall opens here with a low stage and a cracked rail. Tattered curtains\n"
    "hang in strips along the back wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room238", "east",
    "domain/original/area/anshelm/room414", "north",
  });

  set_light(1);
}
