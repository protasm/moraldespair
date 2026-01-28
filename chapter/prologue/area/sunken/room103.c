inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Pitted Turn";
  long_desc = "A low basin of ash and grit sits where the ground once stood higher. Wind has piled sand against one side, leaving the other scoured bare.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room102", "north",
    "chapter/prologue/area/sunken/room104", "south",
    "chapter/prologue/area/sunken/room999", "east",
    "chapter/prologue/area/sunken/room998", "west",
  });

  set_light(1);
}
