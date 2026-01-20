inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Kiln";
  long_desc = "A soot-black kiln squats against the wall, its mouth choked with ash and dust. Fused beads and curled shards glitter faintly amid rot and mildew, and a workbench has split under the weight of silence.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room155", "east",
  });
}
