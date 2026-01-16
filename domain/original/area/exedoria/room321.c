inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Scrap Yard";
  long_desc = "A yard of scattered metal and broken carts sprawls between low fences. Rusted\nframes and bent tools lie half buried in dirt.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room315", "south",
  });
}
