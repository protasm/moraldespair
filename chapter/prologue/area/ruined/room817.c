inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Manor";
  long_desc = "Carved pillars and a broad stair rise into shadow, their edges softened by rot. Mildewed drapes hang in tatters, and the air is heavy with dust. A broken crest above the hearth hints at a once-proud household.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room818", "up",
    "chapter/prologue/area/ruined/room152", "west",
  });
}
