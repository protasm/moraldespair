inherit "/room/room";

void create() {
  ::create();

  short_desc = "Broken Row";
  long_desc =
    "Low buildings crowd the street, their doorways gaping and dark. Rainwater\n"
    "gathers in the ruts where carts once passed.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room416",
    "south" : "/chapter/prologue/area/refuge/room240",
    "north" : "/chapter/prologue/area/refuge/room242",
  ]);

  set_light(1);
}
