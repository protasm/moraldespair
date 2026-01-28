inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dim Walk";
  long_desc = "A narrow walk runs beneath slumped beams and the last remains of a shaded trellis. Motes of dust cling to the air, and the stones are slick with old rot.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room/room227",
    "south":"/chapter/prologue/area/ruined/room/room221",
    "west":"/chapter/prologue/area/ruined/room/room119",
    "east":"/chapter/prologue/area/ruined/room/room117",
  ]);

}
