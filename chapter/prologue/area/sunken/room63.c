inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble-Strewn Walk";
  long_desc = "An open stretch of hard-packed grit marks a crossing of several lines. Splintered tiles crunch underfoot, mixed with crushed brick.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room62", "north",
    "chapter/prologue/area/sunken/room64", "south",
    "chapter/prologue/area/sunken/room94", "east",
    "chapter/prologue/area/sunken/room72", "west",
  });

  set_light(1);
}
