inherit "/room/room";

void create() {
  ::create();

  short_desc = "Pitted Turn";
  long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has piled sand against one side, leaving the other scoured bare.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room16", "north",
    "chapter/prologue/area/sunken/room18", "south",
  });

  set_light(1);
}
