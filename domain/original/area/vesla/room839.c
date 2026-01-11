inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Fallen Choir";
  long_desc = "A narrow nave ends at a cracked lectern, its wood softened by rot.\n"
              + "Faded murals curl from the damp walls, and a line of benches sits in dust and\n"
              + "mildew, facing a silence that never lifts.\n";
  dest_dir = ({
    "domain/original/area/vesla/room820", "east",
  });
}
