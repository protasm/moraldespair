inherit "room/room";

void create() {
  ::create();

  short_desc = "Fallen Choir";
  long_desc = "A narrow nave ends at a cracked lectern, its wood softened by rot. Faded murals curl from the damp walls, and a line of benches sits in dust and mildew, facing a silence that never lifts.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room820", "east",
  });

  set_light(1);
}
