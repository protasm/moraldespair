inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Wind-Scoured Reach";
  long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room80", "north",
    "chapter/prologue/area/sunken/room82", "south",
  });

  set_light(1);
}
