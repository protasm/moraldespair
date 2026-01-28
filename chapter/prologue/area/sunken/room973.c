inherit "/room/room";

void create() {
  ::create();

  short_desc = "Shattered Cut";
  long_desc = "The ground levels out into a broad, empty spread of fractured flagstone. Small pits and cracks show where repeated blows split the surface.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room986", "north",
    "chapter/prologue/area/sunken/room974", "south",
    "chapter/prologue/area/sunken/room15", "west",
  });

  set_light(1);
}
