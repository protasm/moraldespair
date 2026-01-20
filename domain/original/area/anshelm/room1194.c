inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble Yard";
  long_desc =
    "This open yard is choked with split stone and mortar dust. A collapsed crane\n"
    "frame lies among the weeds.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room255", "west",
  });

  set_light(1);
}
