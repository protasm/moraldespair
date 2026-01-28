inherit "/room/room";

void create() {
  ::create();

  short_desc = "Hollow Gap";
  long_desc = "A stub of wall creates a blind corner before the way slips onward. Splintered tiles crunch underfoot, mixed with crushed brick. The silence presses close between the broken walls.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room96", "north",
  });

  set_light(1);
}
