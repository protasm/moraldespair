inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "North Passage";
  long_desc =
    "The street tightens, squeezed by leaning masonry. Loose slate tiles litter the\n"
    "edges of the road.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room258", "east",
    "domain/original/area/anshelm/room260", "west",
  });
}
