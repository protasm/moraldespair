inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Hall";
  long_desc =
    "A long chamber lies open and empty, its ceiling partially collapsed. Soot\n"
    "stains the stone where braziers once burned.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1153", "east",
    "chapter/prologue/area/anshelm/room1137", "west",
  });

  set_light(1);
}
