inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Iron Alcove";
  long_desc = "Rust flakes from a split rack, and the floor is filmed with dust and old grit. A\n"
              + "warped counter and dull iron hooks suggest where blades once hung, now left to\n"
              + "mildew and silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room220", "west",
    "domain/original/area/vesla/room116", "north",
  });
}
