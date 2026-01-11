inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Iron Alcove";
  long_desc = "Rust flakes from a split rack, and the floor is filmed\n"
              + "with dust and old grit. A warped counter and dull iron\n"
              + "hooks suggest where blades once hung, now left to mildew\n"
              + "and silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room220", "west",
    "domain/original/area/vesla/room116", "north",
  });
}
