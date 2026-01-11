inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stitch Loft";
  long_desc = "Rot-softened padding slumps in a heap, and dust clogs\n"
              + "the seams of a collapsed frame. A few dull buckles\n"
              + "and a cracked mannequin hint at fittings once done\n"
              + "here, now lost to mildew.\n";
  dest_dir = ({
    "domain/original/area/vesla/room232", "south",
  });
}
