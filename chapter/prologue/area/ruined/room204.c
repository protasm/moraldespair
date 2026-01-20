inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc = "Loose stone chips blanket the ground, and the walls carry streaks of water rot and mildew. A line of small iron mounts runs along the lintel, hints of old bells or lamps now gone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room203", "east",
    "chapter/prologue/area/ruined/room140", "west",
  });
}
