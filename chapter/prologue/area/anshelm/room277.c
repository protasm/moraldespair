inherit "room/room";

void create() {
  ::create();

  short_desc = "Soldier Row";
  long_desc =
    "The buildings here are little more than low walls. Grass grows thick where\n"
    "floors once lay.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room278",
    "west" : "/chapter/prologue/area/anshelm/room276",
  ]);

  set_light(1);
}
