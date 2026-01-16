inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruin Passage";
  long_desc =
    "A narrow passage runs through broken walls, half open to the air. Rubble\n"
    "mounds force the path to one side.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room251", "west",
  });
}
