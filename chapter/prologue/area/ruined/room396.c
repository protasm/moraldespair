inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Curios";
  long_desc = "Narrow shelves sag under warped boxes and tarnished curios, all buried in dust. The air is sweet with mildew, and the floorboards have bowed around a collapsed display case. A cracked mirror leans in back, its gilt peeling away.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room208", "south",
  });
}
