inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "North Passage";
  long_desc =
    "The street tightens, squeezed by leaning masonry. Loose slate tiles litter the\n"
    "edges of the road.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room258",
    "west" : "/chapter/prologue/area/refuge/room260",
  ]);

  set_light(1);
}
