inherit "room/room";

void create() {
  ::create();

  short_desc = "Barracks";
  long_desc =
    "Low bunks have collapsed into heaps of wood and straw. The air carries a trace\n"
    "of old straw and dust.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room1146",
    "west" : "/chapter/prologue/area/anshelm/room1144",
  ]);

  set_light(1);
}
