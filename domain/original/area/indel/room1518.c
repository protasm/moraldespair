inherit "room/room";

void create() {
  ::create();

  short_desc = "Lichen Faded Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1519", "east",
    "domain/original/area/indel/room1517", "west",
  });

  set_light(1);
}
