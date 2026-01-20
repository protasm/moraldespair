inherit "room/room";

void create() {
  ::create();

  short_desc = "Ashen Way";
  long_desc = "Charred stone and blackened beams mark this stretch, now silent and ruined. Ash lies under drifted dust, and mildewed rubble clogs the broken curb where small fronts once opened in ash and rot.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room841", "west",
    "chapter/prologue/area/ruined/room148", "south",
  });

  set_light(1);
}
