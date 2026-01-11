inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Taproom";
  long_desc = "Rot-softened beams sag over a long counter gone gray with dust and mildew.\n"
              + "Benches lie broken in the hush, and a sour stain clings where drink once\n"
              + "spilled. The hearth is cold, its iron hooks rusted and half-buried in grit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room223", "west",
    "domain/original/area/vesla/room221", "east",
    "domain/original/area/vesla/room119", "north",
  });
}
