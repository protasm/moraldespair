inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Stall";
  long_desc = "An empty shell of a room stands with a cracked lintel and dusted floor. Rotted beams and a few iron brackets suggest a trade space that never returned.";
  dest_dir = ({
    "domain/original/area/vesla/room795", "north",
  });
}
