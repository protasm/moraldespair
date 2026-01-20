inherit "room/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "The road dips slightly, collecting a shallow sheen of silt from past rains. Cracked thresholds line both sides, leading into roofless interiors.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room174",
      "north":"/chapter/prologue/area/ruined/room176",
    ]);

  set_light(1);
}
