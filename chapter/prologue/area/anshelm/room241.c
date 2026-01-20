inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Row";
  long_desc =
    "Low buildings crowd the street, their doorways gaping and dark. Rainwater\n"
    "gathers in the ruts where carts once passed.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room416", "west",
    "chapter/prologue/area/anshelm/room240", "south",
    "chapter/prologue/area/anshelm/room242", "north",
  });

  set_light(1);
}
