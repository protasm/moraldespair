inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dim Walk";
  long_desc = "A narrow walk runs beneath slumped beams and the last remains of a shaded trellis. Motes of dust cling to the air, and the stones are slick with old rot.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room227", "north",
    "chapter/prologue/area/ruined/room221", "south",
    "chapter/prologue/area/ruined/room119", "west",
    "chapter/prologue/area/ruined/room117", "east",
  });
}
