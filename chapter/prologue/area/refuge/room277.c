inherit "room/room";

void create() {
  ::create();

  short_desc = "Soldier Row";
  long_desc =
    "The buildings here are little more than low walls. Grass grows thick where\n"
    "floors once lay.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room278",
    "west" : "/chapter/prologue/area/refuge/room276",
  ]);

  set_light(1);
}
