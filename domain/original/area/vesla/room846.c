inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Cinder Row";
  long_desc = "Charcoal streaks still mark the stones, now silent and weatherworn beneath\n"
              + "lichen and mildew. Collapsed rafters and dusted crockery sit in rot, hinting\n"
              + "at a small shop long abandoned.\n";
  dest_dir = ({
    "domain/original/area/vesla/room845", "west",
    "domain/original/area/vesla/room147", "north",
  });
}
