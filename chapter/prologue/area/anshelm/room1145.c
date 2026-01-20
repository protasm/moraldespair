inherit "room/room";

void create() {
  ::create();

  short_desc = "Barracks";
  long_desc =
    "Low bunks have collapsed into heaps of wood and straw. The air carries a trace\n"
    "of old straw and dust.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1146", "east",
    "chapter/prologue/area/anshelm/room1144", "west",
  });

  set_light(1);
}
