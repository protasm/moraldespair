inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Tight Passage";
  long_desc =
    "A narrow passage squeezes between two thick walls of stone. The floor is\n"
    "polished smooth where many feet once passed.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room265", "west",
  });
}
