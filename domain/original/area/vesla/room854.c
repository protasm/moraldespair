inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Scented Stall";
  long_desc = "Rusted tins and cracked jars sit on sagging shelves, silent beneath dust and\n"
        + "mildew. A faint, stale sweetness clings to the rot, hinting at spice trade in\n"
        + "quiet neglect.\n";
  dest_dir = ({
    "domain/original/area/vesla/room139", "west",
  });
}
