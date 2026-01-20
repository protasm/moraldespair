inherit "room/room";

void create() {
  ::create();

  short_desc = "Scrap Yard";
  long_desc = "A yard of scattered metal and broken carts sprawls between low fences. Rusted\nframes and bent tools lie half buried in dirt.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room315", "south",
  });

  set_light(1);
}
