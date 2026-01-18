inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Mossed Way";
  long_desc = "Broken curbstones edge a long, silent way, their faces dark with mildew and rain stain. A scatter of toppled posts and empty brackets hints at old markers now swallowed by grit.";
  dest_dir = ({
    "domain/original/area/vesla/room200", "south",
    "domain/original/area/vesla/room962", "east",
    "domain/original/area/vesla/room198", "north",
  });
}
