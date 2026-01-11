inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dim Walk";
  long_desc = "A narrow walk runs beneath slumped beams and the last remains of a shaded\n"
              + "trellis. Motes of dust cling to the air, and the stones are slick with old rot.\n";
  dest_dir = ({
    "domain/original/area/vesla/room227", "north",
    "domain/original/area/vesla/room221", "south",
    "domain/original/area/vesla/room119", "west",
    "domain/original/area/vesla/room117", "east",
  });
}
