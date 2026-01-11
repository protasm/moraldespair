inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "The avenue slopes toward the river quarter, the basalt slick with old stains.\n"
              + "A scatter of masonry narrows the passage, leaving the street choked and quiet.\n";
  dest_dir = ({
    "domain/original/area/vesla/room143", "south",
    "domain/original/area/vesla/room850", "east",
    "domain/original/area/vesla/room141", "north",
  });
}
