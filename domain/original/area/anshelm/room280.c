inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "East Barracks";
  long_desc =
    "The road ends near a heap of collapsed roof tiles. A rusted bell frame tilts\n"
    "in the rubble.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room279", "west",
    "domain/original/area/anshelm/room1201", "south",
  });
}
