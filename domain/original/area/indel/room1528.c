inherit "room/room";

void create() {
  ::create();

  short_desc = "Fallen Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1527", "north",
    "domain/original/area/indel/room1529", "south",
  });

  set_light(1);
}
