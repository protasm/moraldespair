inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Walk";
  long_desc = "A quiet stretch of stone runs west, its seams filled with\n"
              + "grit and grass. The remnants of a low railing sag along the\n"
              + "edge, half buried in dust.\n";
  dest_dir = ({
    "domain/original/area/vesla/room124", "west",
    "domain/original/area/vesla/room122", "east",
    "domain/original/area/vesla/room411", "north",
  });
}
