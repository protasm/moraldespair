inherit "/room/room";

void create() {
  ::create();

  short_desc = "Drifted Platform";
  long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room108", "north",
    "chapter/prologue/area/sunken/room98", "south",
  });

  set_light(1);
}
