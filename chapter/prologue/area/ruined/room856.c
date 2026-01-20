inherit "room/room";

void create() {
  ::create();

  short_desc = "Shaving Shed";
  long_desc = "The floor is buried in old shavings turned to pulp, silent and ruined. Dulled chisels and a chipped mallet lie in dust, mildew, and rot, hinting at carved work left to waste.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room138", "east",
  });

  set_light(1);
}
