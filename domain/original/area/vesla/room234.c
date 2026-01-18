inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stitch Loft";
  long_desc = "Rot-softened padding slumps in a heap, and dust clogs the seams of a collapsed frame. A few dull buckles and a cracked mannequin hint at fittings once done here, now lost to mildew.";
  dest_dir = ({
    "domain/original/area/vesla/room232", "south",
  });
}
