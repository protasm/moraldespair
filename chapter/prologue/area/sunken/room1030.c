inherit "/room/room";

void create() {
  ::create();

  short_desc = "Sunken Span";
  long_desc = "A gap between toppled arches forms a narrow throat in the route. Soot stains cling to the stone, and the air tastes of old smoke.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room29", "north",
    "chapter/prologue/area/sunken/room1032", "east",
    "chapter/prologue/area/sunken/room1031", "west",
  });

  set_light(1);
}
