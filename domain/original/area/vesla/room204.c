inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc =
    "Loose stone chips blanket the ground, and the walls carry streaks of water\n"
    "rot and mildew. A line of small iron mounts runs along the lintel, hints of\n"
    "old bells or lamps now gone.\n";
  dest_dir = ({
    "domain/original/area/vesla/room203", "east",
    "domain/original/area/vesla/room140", "west",
  });
}
