inherit "room/room";

void create() {
  ::create();

  short_desc = "Shaded Lane";
  long_desc =
    "The street stays in shadow beneath overhanging roofs. Damp plaster flakes from\n"
    "the walls in thin curls.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room247", "west",
    "chapter/prologue/area/anshelm/room245", "east",
    "chapter/prologue/area/anshelm/room249", "south",
  });

  set_light(1);
}
