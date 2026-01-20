inherit "room/room";

void create() {
  ::create();

  short_desc = "Charred Lane";
  long_desc = "Fire-split timbers jut from the stonework, soft with mildew and long silent in ruin. Dust coats the old thresholds, and rot gnaws at doorframes that hint at narrow rooms now fallen and empty.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room146",
    "east":"/chapter/prologue/area/ruined/room841",
    "north":"/chapter/prologue/area/ruined/room844",
  ]);

  set_light(1);
}
