inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sunken Span";
  long_desc = "A gap between toppled arches forms a narrow throat in the route. Soot stains cling to the stone, and the air tastes of old smoke.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room6", "east",
    "chapter/prologue/area/sunken/room4", "west",
  });

  set_light(1);
}
