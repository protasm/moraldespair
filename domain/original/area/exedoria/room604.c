inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Private Yard";
  long_desc = "A low wall encloses a yard gone to weeds. A warped signpost leans among the\ngrass.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room907", "northeast",
    "domain/original/area/exedoria/room910", "northwest",
    "domain/original/area/exedoria/room338", "south",
  });
}
