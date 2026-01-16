inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Hall";
  long_desc =
    "A long chamber lies open and empty, its ceiling partially collapsed. Soot\n"
    "stains the stone where braziers once burned.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1153", "east",
    "domain/original/area/anshelm/room1137", "west",
  });
}
