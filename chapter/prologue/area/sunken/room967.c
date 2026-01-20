inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble-Strewn Walk";
  long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room1125", "north",
    "chapter/prologue/area/sunken/room59", "east",
  });

  set_light(1);
}
