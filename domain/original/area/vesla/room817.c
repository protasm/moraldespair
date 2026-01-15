inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Manor";
  long_desc = "Carved pillars and a broad stair rise into shadow, their edges softened by\n"
              + "rot. Mildewed drapes hang in tatters, and the air is heavy with dust. A broken\n"
              + "crest above the hearth hints at a once-proud household.\n";
  dest_dir = ({
    "domain/original/area/vesla/room818", "up",
    "domain/original/area/vesla/room152", "west",
  });
}
