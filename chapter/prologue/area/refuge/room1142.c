inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ruined Hall";
  long_desc =
    "A long chamber lies open and empty, its ceiling partially collapsed. Soot\n"
    "stains the stone where braziers once burned.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1153",
    "west" : "/chapter/prologue/area/refuge/room1137",
  ]);

  set_light(1);
}
