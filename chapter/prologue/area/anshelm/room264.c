inherit "room/room";

void create() {
  ::create();

  short_desc = "North Run";
  long_desc =
    "The road here is uneven, with stones heaved by roots. A bent streetlamp rises\n"
    "from a base of cracked stone.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room260",
    "north" : "/chapter/prologue/area/anshelm/room265",
  ]);

  set_light(1);
}
