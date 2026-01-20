inherit "room/room";

void create() {
  ::create();

  short_desc = "Wind-Scoured Reach";
  long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room61", "north",
    "chapter/prologue/area/sunken/room63", "south",
    "chapter/prologue/area/sunken/room972", "east",
    "chapter/prologue/area/sunken/room971", "west",
  });

  set_light(1);
}
