inherit "room/room";

void create() {
  ::create();

  short_desc = "Lane Crossing";
  long_desc =
    "A side lane cuts west toward narrower houses. The corner stones are chipped\n"
    "and slick with lichen.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room245", "west",
    "domain/original/area/anshelm/room250", "east",
    "domain/original/area/anshelm/room243", "south",
  });

  set_light(1);
}
