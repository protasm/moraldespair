inherit "room/room";

void create() {
  ::create();

  short_desc = "Lonely Row";
  long_desc =
    "Shuttered storefronts line the way, their thresholds choked with weeds. The\n"
    "stone is slick where rainwater pools.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room255", "south",
    "domain/original/area/anshelm/room257", "north",
  });

  set_light(1);
}
