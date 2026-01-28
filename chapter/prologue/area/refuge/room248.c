inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Halfbuilt Court";
  long_desc =
    "Unfinished walls stand in a rough square, their mortar crumbled into dust.\n"
    "Timber scaffolds lie splintered across the ground.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/refuge/room247",
  ]);

  set_light(1);
}
