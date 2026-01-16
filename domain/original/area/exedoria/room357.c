inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cobble Hall";
  long_desc = "Round cobbles form the hall floor, slick with age. The walls narrow as the\ncorridor stretches on.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room358", "south",
    "domain/original/area/exedoria/room360", "east",
    "domain/original/area/exedoria/room356", "north",
  });
}
