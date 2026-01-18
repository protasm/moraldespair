inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Halfbuilt Court";
  long_desc =
    "Unfinished walls stand in a rough square, their mortar crumbled into dust.\n"
    "Timber scaffolds lie splintered across the ground.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room247", "north",
  });
}
