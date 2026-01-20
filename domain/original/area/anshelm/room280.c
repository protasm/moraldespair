inherit "room/room";

void create() {
  ::create();

  short_desc = "East Barracks";
  long_desc =
    "The road ends near a heap of collapsed roof tiles. A rusted bell frame tilts\n"
    "in the rubble.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room279", "west",
    "domain/original/area/anshelm/room1201", "south",
  });

  set_light(1);
}
