inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Curios";
  long_desc = "Narrow shelves sag under warped boxes and tarnished curios, all buried in dust. The air is sweet with mildew, and the floorboards have bowed around a collapsed display case. A cracked mirror leans in back, its gilt peeling away.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room208",
  ]);

  set_light(1);
}
