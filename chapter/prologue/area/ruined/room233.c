inherit "room/room";

void create() {
  ::create();

  short_desc = "Iron Alcove";
  long_desc = "Rust flakes from a split rack, and the floor is filmed with dust and old grit. A warped counter and dull iron hooks suggest where blades once hung, now left to mildew and silence.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room220", "west",
    "chapter/prologue/area/ruined/room116", "north",
  });

  set_light(1);
}
