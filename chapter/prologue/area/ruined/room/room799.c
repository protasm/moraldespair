inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Wet Cut";
  long_desc = "Moisture beads on the close walls, and the paving is dark with mildew. A rusted hinge stump and scored stone hint at a narrow door once kept shut.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room/room802",
    "east":"/chapter/prologue/area/ruined/room/room800",
    "south":"/chapter/prologue/area/ruined/room/room798",
  ]);

}
