inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Club";
  long_desc =
    "A small hall opens here with a low stage and a cracked rail. Tattered curtains\n"
    "hang in strips along the back wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room238", "east",
    "chapter/prologue/area/anshelm/room414", "north",
  });

  set_light(1);
}
