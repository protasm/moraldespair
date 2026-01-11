inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Kiln";
  long_desc = "A soot-black kiln squats against the wall, its mouth choked with ash and dust.\n"
              + "Fused beads and curled shards glitter faintly amid rot and mildew, and a\n"
              + "workbench has split under the weight of silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room155", "east",
  });
}
