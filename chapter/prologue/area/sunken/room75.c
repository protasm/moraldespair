inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Drifted Platform";
  long_desc = "Scattered piers suggest a once-long span, now broken into bays. Wind has piled sand against one side, leaving the other scoured bare.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room1095", "south",
    "chapter/prologue/area/sunken/room74", "east",
    "chapter/prologue/area/sunken/room76", "west",
  });

  set_light(1);
}
