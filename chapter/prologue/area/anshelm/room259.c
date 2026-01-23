inherit "room/room";

void create() {
  ::create();

  short_desc = "North Passage";
  long_desc =
    "The street tightens, squeezed by leaning masonry. Loose slate tiles litter the\n"
    "edges of the road.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room258",
    "west" : "/chapter/prologue/area/anshelm/room260",
  ]);

  set_light(1);
}
