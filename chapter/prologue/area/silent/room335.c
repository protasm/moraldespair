inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Street";
  long_desc = "A straight street runs between low walls and empty storefronts. Loose grit\ncrunches over the paving.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room336", "east",
    "chapter/prologue/area/silent/room334", "west",
  });

  set_light(1);
}
