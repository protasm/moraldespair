inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Gate Foyer";
  long_desc =
    "This foyer exists to demonstrate directional disambiguation for gates\n"
    "that share the same name. A hatch sits to the east and another to the\n"
    "west; use 'open east hatch' or 'open west hatch' to be explicit.";
}
