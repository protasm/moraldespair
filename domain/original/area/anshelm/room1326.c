inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Guild";
  long_desc =
    "A once-grand hall stands here, its pillars chipped and dim. Faded motifs curl\n"
    "along the walls like ghosts of paint.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room283", "south",
  });

  set_light(1);
}
