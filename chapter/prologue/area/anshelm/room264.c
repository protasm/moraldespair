inherit "room/room";

void create() {
  ::create();

  short_desc = "North Run";
  long_desc =
    "The road here is uneven, with stones heaved by roots. A bent streetlamp rises\n"
    "from a base of cracked stone.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room260", "south",
    "chapter/prologue/area/anshelm/room265", "north",
  });

  set_light(1);
}
