inherit "room/room";

void create() {
  ::create();

  short_desc = "Dim Walk";
  long_desc = "A narrow walk runs beneath slumped beams and the last remains of a shaded trellis. Motes of dust cling to the air, and the stones are slick with old rot.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room227",
    "south":"/chapter/prologue/area/ruined/room221",
    "west":"/chapter/prologue/area/ruined/room119",
    "east":"/chapter/prologue/area/ruined/room117",
  ]);

  set_light(1);
}
