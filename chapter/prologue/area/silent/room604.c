inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Private Yard";
  long_desc = "A low wall encloses a yard gone to weeds. A warped signpost leans among the\ngrass.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room907", "northeast",
    "chapter/prologue/area/silent/room910", "northwest",
    "chapter/prologue/area/silent/room338", "south",
  });
}
