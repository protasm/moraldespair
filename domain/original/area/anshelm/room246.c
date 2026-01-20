inherit "room/room";

void create() {
  ::create();

  short_desc = "Shaded Lane";
  long_desc =
    "The street stays in shadow beneath overhanging roofs. Damp plaster flakes from\n"
    "the walls in thin curls.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room247", "west",
    "domain/original/area/anshelm/room245", "east",
    "domain/original/area/anshelm/room249", "south",
  });

  set_light(1);
}
